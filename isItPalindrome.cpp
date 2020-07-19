// question link : https://app.codesignal.com/challenge/GwajfqFiFqbxLpNq9
// first solution
typedef ListNode<int> node;
void reverse(node ** second){
    node * curr= (*second);
    node * prev = NULL;
    node * next=  NULL;
    while(curr){
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    *second = prev;
}

bool isListPalindrome(node * l) {
    int totNodes = 0;
    node * ptr = l;
    while(ptr){
        totNodes++;
        ptr = ptr->next;
    }
    int h = (totNodes % 2 == 0) ? totNodes / 2 : (totNodes / 2) + 1;
    ptr = l;
    node * second = l;
    while(h != 0){
        second = second->next;
        h--;
    }
    reverse(&second);
    while(second){
        if(second->value != ptr->value)  return false;
        second = second->next;
        ptr = ptr->next;
    }
    return true;
}

/* second solution 

typedef ListNode<int> node; 

bool isListPalindrome(node * l) {
    node * ptr = l;
    vector<int> v;
    while(ptr){
        
        v.push_back(ptr->value);
        ptr= ptr->next;
    }
    for(int i = 0;i<v.size() / 2;i++){
        if(v[i] != v[v.size() - i - 1]) return false;
    }
    return true;
}
*/
