class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char>vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int vowelCount = 0;
        int mid = s.length()/2;
        for (int i = 0; i < mid; i++){
            char a = s[i];
            char b = s[mid + i];
            if (vowels.count(a)) vowelCount++;
            if (vowels.count(b)) vowelCount--;
            
        }
        return vowelCount == 0;
    }
};

// class Solution {
// public:
//     bool halvesAreAlike(string s) {
//         unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

//         int vowelCount = 0;
//         int mid = s.length() / 2;
//         for (int i = 0; i < mid; i++) {
//             char a = s[i];
//             char b = s[mid + i];
//             if (vowels.count(a)) vowelCount++;
//             if (vowels.count(b)) vowelCount--;

//         }
//         return vowelCount == 0; // Return true if the two halves have the same number of vowels
//     }
// };

