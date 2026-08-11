class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for(int i = 0; i < typed.size(); i++){
            char check = typed[i];
            if(name[j] == check && j < name.size()){
                j++;
            }
            else if (i > 0 && typed[i] == typed[i - 1]) {
                continue;
            }
            else{
                return false;
            }
        }

        if(j == name.size()){
            return true;
        }
        else return false;
        
    }
};