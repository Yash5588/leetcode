class TextEditor {
public:
    //maniac problem took 4 hours
    list<char> lst;
    list<char> ::iterator iter = lst.begin(),temp;
    TextEditor() {
        lst.clear();
    }
    
    void addText(string text) {
        int n = text.size();
        for(int i = 0;i < n;i++) {
            lst.insert(iter,text[i]);
        }
    }
    
    int deleteText(int k) {
        if(iter == lst.begin()) return 0;
        iter--;
        int cnt = 0;
        while(iter != lst.begin() && cnt < k) {
            cnt++;
            iter = lst.erase(iter);
            iter--;
        }
        if(iter == lst.begin() && cnt < k) {
            cnt++;
            iter = lst.erase(iter);
            iter--;
        }
        iter++;
        return cnt;
    }
    
    string cursorLeft(int k) {
        int cnt = 0;
        while(iter != lst.begin() && cnt < k) {
            cnt++;
            iter--;
        }
        string str;
        temp = iter;
        if(temp == lst.begin()) return "";
        temp--;
        cnt = 0;
        while(temp != lst.begin() && cnt < 10) {
            cnt++;
            str += *temp;
            temp--;
        }
        if(temp == lst.begin() && cnt < 10) {
            cnt++;
            str += *temp;
            temp--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    
    string cursorRight(int k) {
        int cnt = 0;
        while(iter != lst.end() && cnt < k) {
            cnt++;
            iter++;
        }
        string str;
        temp = iter;
        if(temp == lst.begin()) return "";
        temp--;
        cnt = 0;
        while(temp != lst.begin() && cnt < 10) {
            cnt++;
            str += *temp;
            temp--;
        }
        if(temp == lst.begin() && cnt < 10) {
            cnt++;
            str += *temp;
            temp--;
        }
        reverse(str.begin(),str.end());
        return str;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */