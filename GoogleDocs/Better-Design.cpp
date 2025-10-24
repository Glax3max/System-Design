#include<bits/stdc++.h>
using namespace std;

// Abstraction for document element
class DocumentElement{
    public:
        virtual string render() = 0; //pure virtual function
};

// Concrete  implementation for text elements
class TextElement : public DocumentElement{
    private:
        string text;
    public:
        TextElement(string text) {
            this->text = text;
        }
        
        string render() override{
            return text;
        }
};

// Concrete  implementation for image elements
class ImageElement : public DocumentElement{
    private:
        string image;
    public:
        ImageElement(string image) {
            this->image = image;
        }
        
        string render() override{
            return "[Image:"+image+"]";
        }
};

// NewLineElement represents a line break in the documents
class NewLineElement: public DocumentElement {
    public:
        string render() {
            return "\n";
        }
};

// TabElement represents a tab space in the document
class TabElement: public DocumentElement {
    public:
        string render() {
            return "\t";
        }
};

// Document class responsible for holding a collection of elements
class Document {
    private:
        vector<DocumentElement *> documentElements;
    
    public:
        void addElement(DocumentElement* element) {
            documentElements.push_back(element);
        }

    // Renders the document by concatenating the render output of all elements 
        string render() {
            string result;
            for(auto element:documentElements) {
                result += element->render();
            }
            return result;
        }
};

// Persistence Inheritence
class Persistence{
    public:
        virtual void save(string data) = 0;
};

class FileStorage: public Persistence{
    public:
        void save(string data) override {
            ofstream outFile("document.txt");
            if(outFile) {
                outFile << data;
                outFile.close();
                cout<<"Document saved to document.txt" <<endl;
            }else {
                cout<<"Error: Unable to open file for writing"<<endl;
            }
        }
};

class DBStorage : public Persistence {
    public:
        void save(string data) override {
            // save to DB
        }
};

class DocumentEditor{
    private:
        Document* document;
        Persistence* storage;
        string renderedDocument;

    public:
        DocumentEditor(Document* document,Persistence* storage) {
            this->document = document;
            this->storage = storage;
        }

        void addText(string text) {
            document->addElement(new TextElement(text));
        }

        void addImage (string imagePath) {
            document->addElement(new ImageElement(imagePath));
        }

        void addNewLine() {
            document->addElement(new NewLineElement());
        }

         void addTabSpace() {
            document->addElement(new TabElement());
        }

        string renderDocument() {
            if(renderedDocument.empty()) {
                renderedDocument = document->render();
            }
            return renderedDocument;
        }

        void saveDocument() {
            storage->save(renderDocument());
        }
};
int main() {
    Document* document = new Document();
    Persistence* persistence = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document,persistence);

    // Simulate a client using the editor with common text formatting feature
    editor->addText("Hello! world");
    editor->addNewLine();
    editor->addText("This is a real world document editor example");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space");
    editor->addNewLine();
    editor->addImage("piture.jpg");
    
    // Render and display the final document
    cout<< editor->renderDocument()<<endl;

    editor->saveDocument();
    
    return 0;
}