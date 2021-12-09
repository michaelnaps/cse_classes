function [c] = kmeans(filename, k)
    fileID = fopen(filename);
    p = cell2mat(textscan(fileID, '%f %f'));
    fclose(fileID);
    
    xmax = max(p(:,1));
    ymax = max(p(:,2));
    
    xmin = min(p(:,1));
    ymin = min(p(:,2));
    
    c = zeros(k,1);
    c(:,1) = (xmax - xmin)*rand(k,1) + xmin;
    c(:,1) = (ymax - ymin)*rand(k,1) + ymin;
    
    for i = 1:length(p(:,1))
        for j = 2:k
            
        end
    end
end

