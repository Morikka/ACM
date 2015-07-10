###概述
一般是求小于等于数字N的某些特征数字个数，或者是区间[L,R]的之间的某些特征数字个数，后者一般可以转换成求差的方式来做。
###模板
####数字处理函数
```C++
int f(int num){
    int ans;
    int pos = 0;
    while(num){
        digit[++pos]=num%10;
        num=num/10;
    }
    return dfs( pos, s , true );
}
```
digit为处理串的每个数位的数值。
s为初始的状态。
如果有其他限定条件，`dfs`中可以增加参数。
####`DFS`函数
```c++
int dfs(int l, int s, bool jud) {
    if ( l==-1 ) return s == target_s;
    if ( !e && ~f[l][s] ) return f[l][s];
    int ans = 0;
    int nex = e ? digit[i] : 9;
    for (int d = 0; d <=  nex; ++d)
        ans += dfs( l-1 , new_s( s,d ) , e && d==nex );
    return jud ? ans : f[l][s] = ans;
}
```
f为记忆化数组；
l为当前处理串的第l位（权重表示法，也即后面剩下l+1位待填数）；
s为之前数字的状态（如果要求后面的数满足什么状态，也可以再记一个目标状态t之类，for的时候枚举下t）；
jud表示之前的数是否是上界的前缀（即后面的数能否任意填）。
for循环枚举数字时，要注意是否能枚举0，以及0对于状态的影响，有的题目前导0和中间的0是等价的，但有的不是，对于后者可以在dfs时再加一个状态变量z，表示前面是否全部是前导0，也可以看是否是首位，然后外面统计时候枚举一下位数。It depends.
于是关键就在怎么设计状态。当然做多了之后状态一眼就可以瞄出来。
#####前导零的判断
```c++
int dfs(bool zero)
......
ans+=dfs(zero&&i==0)//不区分前导零与零
ans+=dfs(zero&&i==0&&l>1)//区分前导零与零
```
###题目
链接：【[[kuangbin带你飞]专题十五 数位DP](http://acm.hust.edu.cn/vjudge/contest/view.action?cid=70324#overview)】
####A. 【[CF55D](http://codeforces.com/problemset/problem/55/D)】
#####题意
给定区间[L,R]，求区间完美数字的个数。（一个数字是完美数字当且仅当该数字可整除其所有数位上的非零数）
#####思路
位数上的数字只需要考虑2~9，因此用一个数字`1<<8`来表示有哪些数字出现过。
如果一个数是所有位数的倍数，那么一定是其最小公倍数的倍数，其所有的最小公倍数是2520，所以求和的时候直接对2520取余。
`dp[l][cnt][sum]`，l为数字长度，cnt为位数上有哪些数，sum为数字和。
`dfs(int l,int cnt,int sum,bool jud)`，jud为是否为边界。
####B. 【[HDU4352](http://acm.hdu.edu.cn/showproblem.php?pid=4352)】
#####题意
寻找[L,R]中间所有数字串中LIS（最长上升子序列）为K的数字和。
#####思路
LIS运用动态规划可以在O(nlogn)的时间复杂度解决，此略。
因为最多只有0～9十个数字，因此可以预处理。
sta为LIS的状态，siz[sta]中保存LIS的长度（即二进制中1的个数），nex[sta][l]为在sta中插入数字l之后的LIS状态。
`dp[l][sta][k]`：l为数字长度，sta为当前LIS的状态，k为所要求的LIS长度。
`dfs(int l,int sta,bool zero,bool jud)`：zero判断是否为前导零，jud为是否为边界。
注意：dp[l][sta][k]中，k并不是必须的，然而因为本题样例组数过多且k很小，所以选择增加一维表状态而不是每次都初始化以节约时间。
####C. 【[HDU2089](http://acm.hdu.edu.cn/showproblem.php?pid=2089)】
#####题意
[L,R]中，不含4或62的数字个数。
#####思路
`dp[l][six]`：l为数字长度，six为最后一位数字是否为6。
`dfs(int l,bool six,bool jud)`，jud判断是否为边界。
####D. 【[HDU3555](http://acm.hdu.edu.cn/showproblem.php?pid=3555)】
#####题意
数字中含有49的数字个数。
#####思路
偷了下懒，用C题的代码求不含49的个数，然后做差，居然过了= =b。其实这道题打表都行= =b。
####E. 【[HDU3252](http://poj.org/problem?id=3252)】
#####题意
数字[L,R]中，round number数字的个数。round number即数字转换成二进制后0的个数大于等于1的个数。
#####思路
digit数组中直接保存该数字的二进制形式。
`dp[l][cnt1][cnt2][zero]`：l为数字长度，cnt1为数字0的数字个数，cnt2为数字1的数字个数，zero判断是否为前导零。
`dfs(int l,int cnt1,int cnt2,bool zero,bool jud)`：jud判断是否为边界。
####F.  【[HDU3709](http://acm.hdu.edu.cn/showproblem.php?pid=3709)】
#####题意
统计区间[L,R]中，balanced number的数字个数。balanced number即对于任意一个数字串，假设其有一个数字位，它左边的数字乘距离的和等于它右边的数字乘距离的和，则其为balanced number。
#####思路
枚举作为平衡点的数字位数，最后要减掉（pos-1）因为对于0,计算了0,00,000...重复计算了pos次，只需要保留一次。
`dp[l][o][pos]`：长度为l，平衡点位置为o时的当前状态（pos为0时表示平衡，pos>0则为左边的沉，pos<0则为右边的沉）
`dfs(int l,int o,int pos,bool jud)`：jud判断是否为边界。
注意只要pos<0就可以返回false。
####G. 【[HDU3652](http://acm.hdu.edu.cn/showproblem.php?pid=3652)】
#####题意
[1,n]的含数字13且为13的倍数的数字个数。
#####思路
`dp[l][mod][iso][has]`：l为数字长度，mod为当前数字对13的取余值，iso为是否存在，has为最后一位是否为数字1。
`int dfs(int l,int mod,bool iso,bool has,bool jud)`：jud判断是否为边界值。
####H. 【[HDU4734](http://acm.hdu.edu.cn/showproblem.php?pid=4734)】
#####题意
对于每个数字x，都有一个F（x）值，让你求[0,B]中，函数值小于等于F（A）的数字个数。
#####思路
首先计算出F（a）。
`dp[l][sum]`：l为当前数字长度，sum为F（A）减去之前枚举的数字的数字差（如果差为正则代表F（A）大）。
`dfs(int l,int sum,bool jud)`：jud判断是否为边界。
####I. 【[ZOJ3494](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3494)】
#####题意
区间[L，R]的数字转换成`BCD`之后，不含有forbidden code（即长度不超过20的01组成的数字串）的数字个数。
#####思路
forbidden code可以用`trie树`储存。
`dp[l][pos]`：l为数字长度，pos为树上的位置。
 `dfs(int l,int pos,bool zero,bool jud)`：zero判断是否为前导零（注意和数字0区分），jud判断是否为边界。
####J. 【[HDU4507](http://acm.hdu.edu.cn/showproblem.php?pid=4507)】
#####题意
区间[L,R]中，和7无关的数字的平方和是多少？含7的数、数位和为7的倍数、数为7的倍数都是和7有关的数字。
#####思路
`dp[len][sum][remain]`：len为长度，sum为数位和，remain为前缀和。
`dfs(int len,int sum,int remain,bool jud)`jud判断是否为边界。
维护三个数字：个数，和，平方和。
`a[1]^2 + a[2]^2 + … + a[n]^2，新式是 (a[1]+b)^2 + (a[2]+b)^2 + … + (a[n]+b)^2`，按照这样的原理求前缀的平方和。
####K. 【[SPOJ10606](http://www.spoj.com/problems/BALNUM/)】
#####题意
求[L,R]中positive integer的数字个数。positive integer就是对于一个数字串，偶数数字各有奇数个，奇数数字各有偶数个。
#####思路
用一个三进制数字表示每个数字的状态，0为未出现过，1为出现过奇数次，2为出现过偶数次。
`dp[l][s]`：l为数字长度，s为当前所有数字出现的状态。
`dfs(int l,int s,bool zero,bool jud)`：zero判断是否为前导零，jud判断是否为边界。
###参考资料
刘聪《浅谈数位类统计问题》
高逸涵《数位计数问题解法研究》
http://www.cnblogs.com/jffifa/archive/2012/08/17/2644847.html
http://blog.csdn.net/dslovemz/article/details/8540340
http://acm.hust.edu.cn/vjudge/contest/view.action?cid=70324#overview
以及各种搜题解是搜到的blog= =b