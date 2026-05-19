#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outfile("newAjke.txt");
    outfile << "int main()\n";
    outfile << "float y =5.8;\n";
    outfile << "if(y > 0)\n";
    outfile << "cout << \"Hello, I Love You\";\n";
    outfile << "return 0;\n";
    outfile.close();

    ifstream infile("newAjke.txt");
    char ch;
    string token = "";

    cout << "Tokens with type:\n\n";

    while(infile.get(ch)) {

        if(ch=='"') {
            token = "\"";
            while(infile.get(ch) && ch!='"') {
                token += ch;
            }
            token += "\"";
            cout << token << " (String)\n\n";
            token = "";
        }

        else if( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9') || ch=='.') {
            token += ch;
        }
        else {

            if(token != "") {
                // Keywords
                if(token=="int" || token=="float" || token=="double" || token=="char" ||
                   token=="if" || token=="else" || token=="while" || token=="for" ||
                   token=="return" || token=="void" || token=="main" || token=="cout" || token=="cin") {
                    cout << token << " (Keyword)\n\n";
                }
                else {

                    bool isNum = true;
                    int dotCount = 0;
                    for(int i=0;i<token.length();i++) {
                        if(token[i]=='.') dotCount++;
                        else if(token[i]<'0' || token[i]>'9') isNum=false;
                    }
                    if(isNum && dotCount<=1) cout << token << " (Constant)\n\n";
                    else cout << token << " (Identifier)\n\n";
                }
                token = "";
            }


            if(ch!=' ' && ch!='\n' && ch!='\t') {
                if(ch=='<' && infile.peek()=='<') {
                    infile.get(ch);
                    cout << "<< (Operator)\n\n";
                }
                else if(ch=='=' || ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='>' || ch=='<') {
                    cout << ch << " (Operator)\n\n";
                }
                else if(ch=='(' || ch==')' || ch=='{' || ch=='}' || ch==';') {
                    cout << ch << " (Special Symbol)\n\n";
                }
            }
        }
    }

    infile.close();
    return 0;
}
