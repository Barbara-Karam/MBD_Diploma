function [mean,standard] = computeStatistics(varargin)
numArgs = nargin;
sum = 0;
for i = 1:numArgs
    sum = sum + varargin{i};
end
mean=sum/numArgs;
sumSq = 0;
for i = 1:numArgs
    term = (varargin{i}-mean)^2;
    sumSq = sumSq + term;
end
standard = sqrt(sumSq/numArgs);
end
