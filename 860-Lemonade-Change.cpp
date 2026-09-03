class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> billCnt(3, 0);

        for (int i = 0; i < bills.size(); i++) {

            if ((bills[i] == 10 && billCnt[0] == 0) ||
                (bills[i] == 20 && ((billCnt[1] == 0 || billCnt[0]==0) && billCnt[0] < 3)))
                return false;

            if (bills[i] == 10) {
                billCnt[0]--;
                billCnt[1]++;
            }
            else if (bills[i] == 20) {
                if (billCnt[1] == 0)
                    billCnt[0] -= 3;
                else {
                    billCnt[1]--;
                    billCnt[0]--;
                }
                billCnt[2]++;
            }
            else {
                billCnt[0]++;
            }
        }

        return true;
    }
};