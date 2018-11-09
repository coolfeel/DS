class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int num = 0;
        set<char> s;
        for (int i = 0; i < J.size(); i++)
            s.insert(J[i]);
        for (int i = 0; i < S.size(); i++)
            if (s.count(S[i]))
                num++;
        return num;
    }
};
