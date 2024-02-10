num = input("Enter a number to find if it's even or odd \n");  % Get numerical input directly

if mod(num, 2) == 0  % Use mod() for modulo operation
    disp("The number is even");
else
    disp("The number is odd");
end
