#解题思路
##1001
每3位数一个段落，得到的结果存到一个stack里面，最后出栈就可以得到分段结果，其中需要注意的是每段输出的时候，如果小于10，100，100的时候，需要补0的。如果最终结果在1000以内的，则不需要补0的。
##1002
利用a[i][j]来保存j次幂下面的指数，其中i=0，1，2分别表示两个输入和最终的输出。  
这道题目需要注意的是，最后的输出保留一位小数。
##1003
Dijkstra算法，只是稍微有点变化。  

*	RoadNum[N]用来保存到达这个点有几条路径，这样在每次加入新的为访问的点遍历一遍的时候，如果找到新路径，则RoadNum[j]就是RoadNum[index]，如果出现MinDst想等情况，则累加RoadNum[index]
*	SaveNum[N]用来保存到达这个点最大的救援队数目。每个点在新加入一个点，进行遍历的时候，如果运算遇到MinDst相等的时候，则验证下是否更新SaveNum[j] 
 
这道题目有个需要注意的是，输入路径的时候，两个点的距离是双向的，既A->B == B->A