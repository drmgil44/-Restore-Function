# FunctionDecl - Parameter1

```cpp
void methodDecl(const FunctionDecl *md){
    // declare pointer casted Class
    auto cname = md->getQualifiedNameAsString();
    cname = cname.substr(0,md->getQualifiedNameAsString().length()-md->getNameAsString().length()-2);
    cout<<"class "<<cname<<endl;

    cout<<md->getNameAsString()<<"(";
    paramInput2(md);
    cout<<");"<<endl<<endl;
}
void functionDecl(const FunctionDecl *md){
    // declare function
    cout<<md->getNameAsString()<<"(";
    paramInput(md);
    cout<<");"<<endl;
}

void paramInput(const FunctionDecl *md){
    for(int i=0;i<md->param_size();i++){
        if(i!=0) cout<<",";
        const ParmVarDecl* pDecl = md->getParamDecl(i);
        cout<<pDecl->getDeclName().getAsString();
    }
}

```

- Result
    - Run `note/sample_code/test3.cpp`
```cpp
class TestA
aFunc1();

class TestA
aFunc2(flag);

class TestB
bFunc1(c,x,s);

test1(a,b,c,d);
test2(a,b,c,d,e,e2,f,g,h);
```
