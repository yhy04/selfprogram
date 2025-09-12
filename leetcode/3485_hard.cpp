#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional> 
#include<algorithm>
#include<numeric>
#include<bitset>
#include<set>
#include<bit>
using namespace std;

class Solution {
public:
    class Tree {
    public:
        Tree* children[26] = {};
        int cnt = 0;
        int res = -1;
        Tree() = default;
    };
    Tree root;
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        for (auto& _ : words) {
            Tree* rt = &root;
            for (auto& ch : _) {
                if (!rt->children[ch - 'a'])rt->children[ch - 'a'] = new Tree;
                rt->children[ch - 'a']->cnt++;
                rt = rt->children[ch - 'a'];
            }
        }
        int n = words.size();
        vector<int> ans(n);
        // map<string,int> mp;
        // unordered_map<string,int> mp;
        function<int(Tree*)> dfs;
        dfs = [&](Tree* rt) {
            if (rt->res != -1) {
                return rt->res + 1;
            }
            for (int i = 0; i < 26; i++) {
                if (rt->children[i] && rt->children[i]->cnt >= k)rt->res = max(dfs(rt->children[i]), rt->res);
            }
            if (rt->res == -1)rt->res = 0;
            return rt->res + 1;
            };
        for (int i = 0; i < n; i++) {
            // if(mp.find(words[i])!=mp.end()){ans[i]=mp[words[i]];continue;}
            Tree* rt = &root;
            rt->res = -1;
            for (auto& _ : words[i]) {
                rt->children[_ - 'a']->cnt--;
                rt->children[_ - 'a']->res = -1;
                rt = rt->children[_ - 'a'];
            }
            ans[i] = dfs(&root) - 1;
            // mp[words[i]]=ans[i];
            rt = &root;
            rt->res = -1;
            for (auto& _ : words[i]) {
                rt->children[_ - 'a']->cnt++;
                rt->children[_ - 'a']->res = -1;
                rt = rt->children[_ - 'a'];
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<string> words1 = { "jump","run","run","jump","run" };
    vector<string> words2 = { "dhuhdoj","rtfims","j","js","wvuvcyoqgz","devzivz","guzygqp","upqajgg","nqdwoiemqt","kook","tnbn","lhuionk","unoc","qysjsdms","luwopvrj","qoztnr","c","rzvvbbqvej","mnnzyecta","kkteylzv","jsxpn","pdsp","ixemd","qp","sjtjmtyjyj","eghvrpukvt","uu","rqcayowpy","g","b","l","ja","uxhyagcgep","xdzuibgl","owbzjy","guctiggrw","bbjwmbdo","iowdissob","jjstewils","rwkfhnm","ahoh","uyraffocne","totljxodx","zjcobbtlf","sne","aflnbc","unkt","twmggdq","ijq","jkzx","em","okpgovvd","onv","dczgvgtvl","k","jidfuvexc","gxpepiosx","ikkd","lp","sxgkvnfxb","klvhrw","uaeofi","cipmxa","g","tuz","z","dwlouqdw","myhcng","kz","sqccztamk","cnzcno","avfbpc","vfmi","qc","qxnqviylfj","ixryemtgx","iukcowzev","tcg","pasme","modtjzaj","vlhsidww","edyrsvvdm","kvr","pvjurj","nisjy","a","hwjfobn","a","bhi","ftan","mtctxl","newy","nfcqk","kvykhfzh","fcm","vow","ncsqmace","cyvunziro","cyco","hlfosnmpo","ygnmpc","cfcmvg","tpx","udatqqrvp","q","dy","xqnxscznyg","z","kx","zbze","ddvhhr","fjnelpqa","bozil","anh","vobfei","xhqj","pgaqx","vmvqdslm","e","xpqbzf","tyh","dc","wblvurm","znsty","mars","mskl","zskaiv","scm","e","z","kwlylt","rt","blwhsqfc","maxo","yeotdxxeg","n","lylvwieuu","ajpcyl","uxifgpil","ihq","itmuxpkuj","lujqvrqh","chbkypnbw","ucyunuwc","x","sczyn","a","qtftntf","ercwgrs","vndqapi","njrcs","ykm","uwkvqkcfcw","ykcmaslhls","joatch","psy","vsabygk","riahrappu","fidfzdv","fa","oy","lwtg","tu","ndr","iopk","x","rpwsi","taaszky","crazjjw","su","wpfuaigkj","ycxbpltf","lgsg","xyzgwws","x","jivp","jinpstemnj","u","wmbdmn","lswwmartww","ziedtubcj","q","rzwqautoiu","dvhoigjirk","zsi","ci","jdjxinxv","yvj","teicu","pzijwfxlpk","iui","ypd","blgo","xqbzwje","osqymf","y","unnwddxk","djuyy","jcb","sywqvdcc","wvhrua","qfiz","v","ppzgeydrrh","mogd","tzcyqs","hovynymfx","numhqb","wuxiixuczp","fcjdx","izuyr","dskqx","w","xfvlw","o","typ","uerfvbw","rckjbiw","ugxyehgxm","vlaswft","iefkerdyj","kl","vrutf","amssrgh","ahfl","tyo","wcjesdfnbg","a","qbxmedxiz","yirhfmmpu","ekk","kcepbufwtb","p","ibfm","su","fo","ayrl","syj","zsyle","rqtziyqdl","k","jzmoc","zyc","ctfelsk","y","lwfgrhwceb","wkxd","tqyw","l","jfahkdvlti","ats","dfs","mltmk","u","seafhcgkxx","wgviiga","jxenvpwswv","axvcqc","xmmqtctbhq","j","unxgqe","wdwjaairrm","nfjxryayns","hzlhz","xezkjevl","m","smb","lo","mihtapqn","ruwdqpgjvd","tvaimdhu","tazelyioi","actzvfleyk","iafd","ctocdwi","gzeuantz","jea","xg","lvkzu","apvxbtt","petkazz","na","nk","xbqrbum","ozgpbuqikd" };
    for (auto& _ : sol.longestCommonPrefix(words1, 2))cout << _ << ' ';;
    cout << '\n';
    for (auto& _ : sol.longestCommonPrefix(words2, 1))cout << _ << ' ';
}