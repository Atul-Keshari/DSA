class Solution {
    public:
        int totalNumbers(vector<int>& digits) {
            set<int> distinctEvenNumbers;
            int size = digits.size();
            for (int i = 0; i < size; i++) {
                if (digits[i] == 0) continue;
                for (int j = 0; j < size; j++) {
                    if (j == i) continue;
                    for (int k = 0; k < size; k++) {
                        if (k == i || k == j) continue;
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (num % 2 == 0) {
                            distinctEvenNumbers.insert(num);
                        }
                    }
                }
            }
    
            return distinctEvenNumbers.size();
        }
    };