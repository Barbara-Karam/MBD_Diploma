File_Id = fopen("Example_One.txt",'w');
if File_Id == 0
    error("unable to open file")
end
Diploma = "MDB";
N_Modules = 10;
C_Module = 'Matlab Basics \n';
fprintf(File_Id,'The name of Diploma is %s',Diploma);
fprintf(File_Id,'The num of modules is %s',N_Modules);
fprintf(File_Id,'The current module is %s',C_Module);
type Example_On.txt;
fclose(File_Id);