#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstdio>

void copyText(std::ofstream& fileout,std::ifstream& filein)
{
    std::string a,b;
    if (filein.is_open()) {
        while (filein>>a>>b)
        {
                fileout<<a<<" "<<b<<std::endl;
        }
    }
}

bool checkUsername(std::string const &name){
    std::string name1,pass1;
    bool result=false;
    std::ifstream myfile ("C:\\Users\\drago\\CLionProjects\\log~auth\\users",std::ios::app | std::ios::in);
    if (myfile.is_open()) {
        while (myfile>>name1>>pass1) {
            if (name == name1) {
                result = true;
            }
        }
    }
    return result;
}
bool checkUser(std::string const &name, std::string const &pass){
    std::string name1,pass1;
    bool result=false;
    std::ifstream myfile ("C:\\Users\\drago\\CLionProjects\\log~auth\\users",std::ios::app | std::ios::in);
    if (myfile.is_open()) {
        while (myfile>>name1>>pass1) {
            if (name==name1 && pass == pass1) {
                result = true;
            }
        }
    }
    return result;
}

bool verifySpaces(std::string a)
{
    bool result=false;
    for(int i=0;i<a.length();i++){
        if(a[i]==' '){
            result=true;
        }
    }
    return result;
}

void enterProgram(){
    std::cout<<"Code your program here! :)";
}
void changePassword(){
    std::string name,password,name1,pass1;
    std::cout<<"Enter your username: "<<std::endl;
    std::cin>>name;
    std::cout<<"Enter your current password: "<<std::endl;
    std::cin>>password;
    if(!checkUser(name,password)){
        std::cout<<"Your username or password is incorrect!"<<std::endl;
        changePassword();
    }
    else
    {
        std::cout<<"Enter your new password: "<<std::endl;
        std::string newpass;
        std::cin>>newpass;
        std::ifstream filein ("C:\\Users\\drago\\CLionProjects\\log~auth\\users",std::ios::in|std::ios::app);
        std::ofstream fileout ("C:\\Users\\drago\\CLionProjects\\log~auth\\users1");
        if (filein.is_open()) {
            while (filein>>name1>>pass1) {
                if (name==name1 && password == pass1) {
                    fileout<< name1<<" "<<newpass<<std::endl;
                }
                else {
                    fileout<< name1 << " " << pass1 << std::endl;
                }
            }
        }
        filein.close();
        fileout.close();
        std::ifstream filein1 ("C:\\Users\\drago\\CLionProjects\\log~auth\\users1",std::ios::in|std::ios::app);
        std::ofstream fileout1 ("C:\\Users\\drago\\CLionProjects\\log~auth\\users");
        copyText(fileout1,filein1);
        filein1.close();
        fileout1.close();
        int status;
        remove("C:\\Users\\drago\\CLionProjects\\log~auth\\users1");
    }
}

void changeUsername(){
    std::string name,password,name1,pass1;
    std::cout<<"Enter your username: "<<std::endl;
    std::cin>>name;
    std::cout<<"Enter your current password: "<<std::endl;
    std::cin>>password;
    if(!checkUser(name,password)){
        std::cout<<"Your username or password is incorrect!"<<std::endl;
        changeUsername();
    }
    else
    {
        std::cout<<"Enter your new username: "<<std::endl;
        std::string newuser;
        std::cin>>newuser;
        std::ifstream filein ("C:\\Users\\drago\\CLionProjects\\log~auth\\users",std::ios::in|std::ios::app);
        std::ofstream fileout ("C:\\Users\\drago\\CLionProjects\\log~auth\\users1");
        if (filein.is_open()) {
            while (filein>>name1>>pass1) {
                if (name==name1 && password == pass1) {
                    fileout<< newuser<<" "<<pass1<<std::endl;
                }
                else {
                    fileout<< name1 << " " << pass1 << std::endl;
                }
            }
        }
        filein.close();
        fileout.close();
        std::ifstream filein1 ("C:\\Users\\drago\\CLionProjects\\log~auth\\users1",std::ios::in|std::ios::app);
        std::ofstream fileout1 ("C:\\Users\\drago\\CLionProjects\\log~auth\\users");
        copyText(fileout1,filein1);
        filein1.close();
        fileout1.close();
        int status;
        remove("C:\\Users\\drago\\CLionProjects\\log~auth\\users1");
    }
}

void Menu(){
    std::cout<<"__Menu__"<<std::endl;
    char a;
    std::cin>>a;
    switch(a){
        case '1':
            enterProgram();
            break;
        case '2':
            changePassword();
            break;
        case '3':
            changeUsername();
            break;
        case '4':
            exit(0);
            break;
    }

}

void Auth(){
    std::string name,password;
    std::cout<<"Enter your username:"<<std::endl;
    std::getline(std::cin>>std::ws,name);
    if(checkUsername(name)) {
        std::cout<<"This username already exists!"<<std::endl;
        Auth();
    }
    else{
        do {
            std::cout << "Enter your password:" << std::endl;
            std::getline(std::cin>>std::ws,password);
            if(verifySpaces(password) && password.length()!=0)
            {
                std::cout<<"Please don't use spaces in your password!"<<std::endl;
            }
            else{

                std::ofstream users;
                users.open("C:\\Users\\drago\\CLionProjects\\log~auth\\users", std::ios::app | std::ios::in);
                if (users.is_open()) {
                    users << name << " " << password << std::endl;
                } else {
                    std::cout << "Unable to open the file." << std::endl;
                }
                users.close();
            }
        } while(verifySpaces(password));
    }
}

void Login(){
    std::string name,password;
    std::cout<<"Enter your username:"<<std::endl;
    std::cin>>name;
    std::cout<<"Enter your password:"<<std::endl;
    std::cin>>password;
    if(!checkUser(name,password)){
        std::cout<<"Your username or password is incorrect!"<<std::endl;
        Login();
    }
    else
    {
        Menu();
    }
}

int main()
{


    std::cout<<"For login press: l"<<std::endl;
    std::cout<<"For authentication press: a"<<std::endl;
    char c;
    std::cin>>c;
    if(c=='l'){
        Login();
    }
    else if(c=='a'){
        Auth();
    }
    return 0;
}
