# FunctionDecl

## Check if tis function or method

```cpp
auto md = Results.Nodes.getNodeAs<clang::FunctionDecl>("x");
        
if(md->isMain()) {
    // cout<<"this function is a main function"<<endl;
}
else if(md->isCXXClassMember()) { //
    // cout<<"this method is a member of a class (struct)"<<endl;
    methodDecl(md);
}
else {
    // cout<<"this is a function"<<endl;
    functionDecl(md);
}
```

## methodDecl(md)
```cpp
void methodDecl(const FunctionDecl *md){
    // declare function
    cout<<"method name : "<<md->getNameAsString()<<endl;

    // declare pointer casted Class
    auto cname = md->getQualifiedNameAsString();
    cname = cname.substr(0,md->getQualifiedNameAsString().length()-md->getNameAsString().length()-2);
    cout<<"class name : "<<cname<<endl;
}
```

- Execute

```cpp
// source code
class TestB{
    public:
        TestA a;
        int bFunc1(int i){
            return i;
        }
};
```

```cpp
// result
method name : bFunc1
class name : TestB
```

## functionDecl(md)
```cpp
void functionDecl(const FunctionDecl *md){
    // declare function
    cout<<"function name : "<<md->getNameAsString()<<endl;
}
```

- Execute

```cpp
// source code
int test1(int a, int *b, int c[3], double d[]){
    c[0] = 1;
    return a;
}
```

```cpp
// result
function name : test1
```