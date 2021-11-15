/* DO NOT REMOVE THIS COMMENT!! CSE 3430 lab2.c AU 21 CODE 05212008 */

/* STUDENT NAME: (REPLACE THIS WITH YOUR NAME) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	struct Data {
		char title[45];
		char author[45];
		int stockNumber;
		float wholesalePrice;
		float retailPrice;
		int wholesaleQuantity;
		int retailQuantity;
	};

	typedef struct Node {
		struct Data book;
		struct Node *next;
	} Node;

void getDataAndBuildList(Node **listHeadPtr);
Node *createNodeAndGetData(void);
void insertNode(Node **listHeadPtr, Node *newNodePtr);
void deleteNode(Node **listHeadPtr, int prodNumberToDelete);
void getUserOption(Node **listHead);
double calculateTotalRevenue(const Node *listHead);
double calculateInvestmentInInventory(const Node *listHead);
double calculateTotalWholesaleCost(const Node *listHead);
double calculateTotalProfit(const Node *listHead);
int calculateTotalBooksSold(const Node *listHead);
double calculateAverageProfit(const Node *listHead);
void printList(const Node *listHead);
void freeAllNodes(Node **listHeadPtr);

int main() {
	Node *listHead = NULL;
	getDataAndBuildList(&listHead);
	getUserOption(&listHead);
	return 0;
}

void getDataAndBuildList(Node **listHeadPtr) {
	Node *newNodePtr;
	printf("Please enter data about the books.\n\n");
	while (newNodePtr = createNodeAndGetData()) {
		insertNode(listHeadPtr, newNodePtr);
	}
}

Node *createNodeAndGetData(void) {
	Node *newNodePtr;
	newNodePtr = malloc (sizeof(Node));
	if (newNodePtr == NULL) {
		printf("Error: memory could not be allocated for enough nodes. ");
		printf("Terminating program!\n");
		exit (0);
	}
	else {
		scanf("%[^\n]", newNodePtr->book.title);
		if (strcmp(newNodePtr->book.title, "END_DATA") == 0) {
			/* free Node if end of book data detected */
			free(newNodePtr);
			return NULL;
		}
		else {
			/* consume newline before author string */
			getchar();
			scanf("%[^\n]s", newNodePtr->book.author);
			scanf("%i", &newNodePtr->book.stockNumber);
			scanf("%f", &newNodePtr->book.wholesalePrice);
			scanf("%f", &newNodePtr->book.retailPrice);
			scanf("%i", &newNodePtr->book.wholesaleQuantity);
			scanf("%i", &newNodePtr->book.retailQuantity);
			/* consume newline before next title string */
			getchar();
		}
		return newNodePtr;
	}
}


void insertNode(Node **listHeadPtr, Node *newNodePtr) {
	Node *traversePtr = *listHeadPtr;
	Node *priorNodePtr;

	if (*listHeadPtr == NULL) {
		*listHeadPtr = newNodePtr;
		newNodePtr->next = NULL;
	}
	else if (newNodePtr->book.stockNumber < traversePtr->book.stockNumber) {
		newNodePtr->next = *listHeadPtr;
		*listHeadPtr = newNodePtr;
	}
	else {
		while (traversePtr != NULL && newNodePtr->book.stockNumber > traversePtr->book.stockNumber) {
			priorNodePtr = traversePtr;
			traversePtr = traversePtr->next;
		}

		if (traversePtr == NULL) {
			traversePtr = newNodePtr;
			newNodePtr->next = NULL;
			priorNodePtr->next = newNodePtr;
		}
		else {
			newNodePtr->next = traversePtr;
			priorNodePtr->next = newNodePtr;
		}
	}

	printf("Book stock number %i was added to the inventory.\n\n", newNodePtr->book.stockNumber);
}

void getUserOption(Node **listHeadPtr) {
	int option;
	Node *newNodePtr;
	int bookNumToDelete;
	do {
		printf("\nPlease enter an integer between 1 and 10 to select an operation on the data:\n");
		scanf("%i", &option);
		getchar();
		switch (option){
			case 1:
				printList (*listHeadPtr);
				break;
			case 2:
				printf("\nTotal revenue: %.2f\n", calculateTotalRevenue(*listHeadPtr));
				break;
			case 3:
				printf("\nTotal wholesale cost: %.2f\n", calculateTotalWholesaleCost(*listHeadPtr));
				break;
			case 4:
				printf("\nTotal investment in inventory: %.2f\n", calculateInvestmentInInventory(*listHeadPtr));
				break;
			case 5:
				printf("\nTotal profit: %.2f\n", calculateTotalProfit(*listHeadPtr));
				break;
			case 6:
				printf("\nTotal number of books sold = %i\n", calculateTotalBooksSold(*listHeadPtr));
				break;
			case 7:
				printf("\nAverage profit: %.2f\n", calculateAverageProfit(*listHeadPtr));
				break;
			case 8:
				printf("\nPlease enter the data for the book you wish to add:\n\n");
				newNodePtr = createNodeAndGetData();
				insertNode(listHeadPtr, newNodePtr);
				break;
			case 9:
				printf("\nPlease enter the book stock number of the book you wish to delete, ");
				printf("followed by enter.\n");
				scanf("%i", &bookNumToDelete);
				deleteNode(listHeadPtr, bookNumToDelete);
				break;
			case 10:
				freeAllNodes(listHeadPtr);
				break;
			default:
				printf("Valid option choices are 1 to 10. Please choose again!\n");
				break;
		}
	} while (option != 10);
}

double calculateTotalRevenue(const Node *listHead) {
	double sumRevenue = 0;
	Node *traversePtr;

	if (listHead == NULL) {
		printf("ERROR: Book list is empty...\n\n");
		return 0;
	}

	/* calculate total revenue of book list */
	sumRevenue = (listHead->book.retailPrice * listHead->book.retailQuantity);
	traversePtr = listHead->next;
	while (traversePtr != NULL) {
		sumRevenue += (traversePtr->book.retailPrice * traversePtr->book.retailQuantity);
		traversePtr = traversePtr->next;
	}

	return sumRevenue;
}

double calculateTotalWholesaleCost(const Node *listHead) {
	double sumWholesale = 0;
	Node *traversePtr;

	if (listHead == NULL) {
		printf("ERROR: Book list is empty...\n\n");
		return 0;
	}

	/* calculate total revenue of book list */
	sumWholesale = (listHead->book.wholesalePrice * listHead->book.wholesaleQuantity);
	traversePtr = listHead->next;
	while (traversePtr != NULL) {
		sumWholesale += (traversePtr->book.wholesalePrice * traversePtr->book.wholesaleQuantity);
		traversePtr = traversePtr->next;
	}

	return sumWholesale;
}

double calculateInvestmentInInventory(const Node *listHead) {
	double sumInvestment = 0;
	Node *traversePtr;

	if (listHead == NULL) {
		printf("ERROR: Book list is empty...\n\n");
		return 0;
	}

	sumInvestment = ((listHead->book.wholesaleQuantity - listHead->book.retailQuantity) * listHead->book.wholesalePrice);
	traversePtr = listHead->next;
	while (traversePtr != NULL) {
		sumInvestment += ((traversePtr->book.wholesaleQuantity - traversePtr->book.retailQuantity) * traversePtr->book.wholesalePrice);
		traversePtr = traversePtr->next;
	}

	return sumInvestment;
}

double calculateTotalProfit(const Node *listHead) {
	double sumRevenue = calculateTotalRevenue(listHead);
	double sumWholesale = calculateTotalWholesaleCost(listHead);
	double sumInvestment = calculateInvestmentInInventory(listHead);

	return sumRevenue + sumInvestment - sumWholesale ;
}

int calculateTotalBooksSold(const Node *listHead) {
	int sumBooksSold = 0;
	Node *traversePtr;

	if (listHead == NULL) {
		printf("ERROR: Book list is empty...\n\n");
		return 0;
	}

	sumBooksSold += listHead->book.retailQuantity;
	traversePtr = listHead->next;
	while (traversePtr != NULL) {
		sumBooksSold += traversePtr->book.retailQuantity;
		traversePtr = traversePtr->next;
	}

	return sumBooksSold;
}

double calculateAverageProfit(const Node *listHead) {
	double sumProfit = calculateTotalProfit(listHead);
	int sumBooksSold = calculateTotalBooksSold(listHead);

	return (sumProfit / sumBooksSold);
}

void deleteNode(Node **listHeadPtr, int stockNumToDelete) {
	Node *traversePtr = *listHeadPtr;
	Node *priorNodePtr;

	if (*listHeadPtr == NULL) {
		printf("ERROR: Book List is empty...\n\n");
		return;
	}
	else if ((*listHeadPtr)->book.stockNumber == stockNumToDelete) {
		*listHeadPtr = traversePtr->next;
		free(traversePtr);
	}
	else {
		while (traversePtr != NULL && traversePtr->book.stockNumber != stockNumToDelete) {
			priorNodePtr = traversePtr;
			traversePtr = traversePtr->next;
		}

		if (traversePtr == NULL) {
			printf("\nERROR: Book stock number %i was not found in the list!\n", stockNumToDelete);
			return;
		}
		else {
			priorNodePtr->next = traversePtr->next;
			free(traversePtr);
		}
	}

	printf("Book stock number %i deleted from the inventory.\n\n", stockNumToDelete);
}

void printList(const Node *listHead) {
	const Node *traversePtr = listHead;
	printf("\nBook list:\n");
	while (traversePtr != NULL) {		/* determine not at end of list */
		printf("%s\n", traversePtr->book.title);
		traversePtr = traversePtr->next;
	}
	printf("\n");
}

void freeAllNodes(Node **listHeadPtr) {
	Node *traversePtr = *listHeadPtr;
	Node *restOfListPtr = *listHeadPtr;
	while (restOfListPtr != NULL) {         /* determine list is not empty */
		restOfListPtr = restOfListPtr->next;
		free(traversePtr);
		traversePtr = restOfListPtr;
	}
	*listHeadPtr = NULL; /* set listHeadPtr back to NULL after space freed */
}