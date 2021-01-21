# FunctionDecl - Parameter Type, Name

```cpp
// string split by index
string string_split(string s, int index){
    char * ctemp = new char[s.length()];
    strcpy(ctemp, s.c_str());
    char* cptr = strtok(ctemp, " ");
    for(int i=0; cptr != NULL; i++){
        if(i==index){
            return cptr;
        }
        cptr = strtok(NULL, " ");
    }
    return NULL;
}
void methodDecl(const FunctionDecl *md){
    // declare pointer casted Class
    auto cname = md->getQualifiedNameAsString();
    cname = cname.substr(0,md->getQualifiedNameAsString().length()-md->getNameAsString().length()-2);
    cout<<"class name : "<<cname<<endl;

    // declare function
    cout<<"method name : "<<md->getNameAsString()<<endl;

    // parameter 
    paramInitialize(md);

}
void functionDecl(const FunctionDecl *md){
    // declare function
    cout<<"function name : "<<md->getNameAsString()<<endl;

    // parameter 
    paramInitialize(md);
}
void paramInitialize(const FunctionDecl *md){
    // declare parameters
    auto pDecl = md->parameters();
    for(int i=0;i<pDecl.size();i++){
        string varName = pDecl[i]->getNameAsString();
        string varType = pDecl[i]->getOriginalType().getAsString();
        string varSize = "";
        bool classFlag = 0;
        
        // ---- Declare param
        // type processing
        if(strstr(varType.c_str(), "class")){ // class or struct case type, string
            varType = string_split(varType, 1);
            classFlag = 1;
        }
        if(strstr(varType.c_str(),"[")){ // array type
            varSize = string_split(varType, 1);
            varType = string_split(varType, 0);
        }
        if(varType == "_Bool"){ // bool type
            varType = "bool";
        }

        cout<<"\t"<<varType<<" "<<varName;
        if(varSize != "")   // array initialize
            cout<<varSize;
        cout<<endl;
        
        // ---- element
        if(varSize != ""){ // array
            string slen = varSize.substr(1,2);
            if(slen != "]"){ // array [3]
                for(int i=0; i<std::stoi(slen); i++){
                    cout<<"\t\t"<<" "<<varName+"["+to_string(i)+"]"<<endl;
                }
            }
        }else if(classFlag == 1 && varType != "string"){ // class or struct, depth 1
            auto fDecl = pDecl[i]->getOriginalType()->getAsCXXRecordDecl();
            for(const auto& field : fDecl->fields()){
                string fieldType = field->getType().getAsString();
                if(strstr(fieldType.c_str(), "class")){ 
                    cout<<"\t\t"<<string_split(fieldType,1)<<" "<<varName+"."+field->getDeclName().getAsString()<<endl;
                }else{
                    cout<<"\t\t"<<fieldType<<" "<<varName+"."+field->getDeclName().getAsString()<<endl;
                }
            }
        }
    }
}
```

- Result
    - Run `note/sample_code/test4.cpp`
```cpp
class name : TestA
method name : aFunc1
class name : TestA
method name : aFunc2
	bool flag
class name : TestB
method name : bFunc1
	char x
	double y
	TestA z
		int z.i1
		string z.s1
function name : test1
	int * b
	int c[3]
		 c[0]
		 c[1]
		 c[2]
	double d[]
function name : test2
	bool a
	char b
	short c
	int d
	long e
	long long e2
	float f
	double g
	long double h
```
