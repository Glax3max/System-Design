#include<bits/stdc++.h>

using namespace std;

class DocumentEditor{
    private:
        vector<string> elements;
        string renderedDocument;
    public:
        void addText(string text) {
            elements.push_back(text);
            cout<<"Text added successFully"<<endl;
        }
        void addImages(string path) {
            elements.push_back(path);
            cout<<"Image added successFully"<<endl;
        }
        string renderDocument() {
           if(renderedDocument.empty()) {
                string result;
                for(auto element : elements) {
                    if(element.size()>4 && (element.substr(element.size()-4) == ".jpg" || element.substr(element.size()-4) == ".png")) {
                        result += "[Image: " +element + "]" + "\n";
                    }else{
                        result += element + "\n";
                    }
                }
                renderedDocument = result;
           }
           return renderedDocument;
        }

        void saveToFile() {
            ofstream file("document.txt");
            if(file.is_open()) {
                file << renderDocument();
                file.close();
                cout<<"Document saved to document.txt\n";
            }else{
                cout<<"Error: Unable to open file for writing."<<endl;
            }
        }
};
int main() {
    DocumentEditor D1;
    D1.addText("Hello");
    D1.addImages("Pixi image");
    D1.renderDocument();
    return 0;
}