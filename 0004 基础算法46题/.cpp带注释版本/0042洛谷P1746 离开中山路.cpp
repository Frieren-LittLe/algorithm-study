#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
// 本题是一个BFS模板题，BFS全称Breadth-First Search —— 广度优先搜索（广搜/宽搜）
// BFS 优先向"广"处扩展，从起点出发，先把距离起点最近的一层节点全部访问完
// 再访问下一层（距离+1）的节点，一层一层向外扩散，像水波纹一样
// 当当前层的所有节点都扩展完，才继续处理下一层，直到队列为空（整张图/搜索树遍历完毕）
// 核心工具：队列（queue）——先进先出，保证"先发现的先处理"，从而按层推进

typedef pair<int, int> PII;// 用 pair 存坐标 (x, y)，方便
// typedef 是 C/C++ 中的关键字，意思是“类型定义”，用来给已有的类型起一个别名
// 如本题中将pair<int,int> 给起了"PII"的别名，以后想要定义一个pair<int,int>变量只需写PII即可 

// pair<变量类型,变量类型>，pair相当于一个精简版的struct，可以装入相关联的两份变量
// "pair<int,int> a"当我们声明好了一个pair<int,int>变量a，a.first表示其前面的int变量,a.second表示其后面的int变量
int n;
int x1, y1, x2, y2;
char m[1005][1005]; // 存地图
int d[1005][1005];	// 存到起点的距离，兼做 vis 数组
// vis 数组（全称 visited 数组，即“访问标记数组”）
// 算法竞赛和数据结构中最常用的辅助数组之一，核心作用是记录某个元素/节点是否已经被处理过


// 本题的解法是，以起点为辐射，不断对起点周边可走地块一圈圈地记录距离起点的距离(即抵达目的地所需要的步数)
// 恰好符合bfs的思想
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int bfs() {
	memset(d, -1, sizeof d);
	// memset，定义在头文件<cstring>
	// 功能：把从 d 开始的连续 sizeof d 个字节，全部设置为 -1

	// 即:把 d 数组里所有的元素都设置成 -1
	queue<PII> q;
	// queue定于于头文件<queue>，是一个先进先出容器，只能队尾进队首出，用 push/pop/front 操作
	// 格式为queue<数据类型> 变量名，如本题含义为声明一个装有<PII>(前面已经声明过pair<int,int>为PII）类型的队列
	// 设置一格区域
	q.push({ x1,y1 });
	// 将{x1，y1}(相当于一对pair)推入q队列
	d[x1][y1] = 0;
	// 在d数组中将d[x1][x2]初始化为0
	while (!q.empty()) {
		auto t = q.front();
		// 令t为q的队首，q.front()表示队列q队首的元素
		// auto 的作用为：让编译器根据右边赋的值，自动推断并确定左边的变量类型
		// 此时的变量类型为pair<int,int>
		q.pop();
		// q.pop()表示将q的队首给弹出
		int x = t.first;
		int y = t.second;
		// 令x为t的第一位，y为第二位
		if (x == x2 && y == y2)return d[x][y];
		// 当t恰为终点时，返回d[x][y]即报出走到此格子需要的步数
		for (int i = 0;i < 4;i++) {
			// 向四个方向各迈一步
			int nx = x + dx[i];
			int ny = y + dy[i];
			// 设置一对防越界的nx，ny
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
				if (d[nx][ny] == -1 && m[nx][ny] == '0') {
					d[nx][ny] = d[x][y] + 1;
					// 当nx，ny检测到未被填入(d[nx][ny]=-1)且可以通行(m[nx][ny] == '0')的格子
					// 使该格子的步数变为上一格子的步数+1
					q.push({ nx,ny });
					// 走到该格子上，继续迈步
					
					// 注意我们在for循环中是在同一层for循环向四个方向都迈了一步了，步数都是 d[x][y]+1
					// 也就是分散开(没被完全阻挡的情况下)来行进，于是呈现出"一层一层向外扩散"的效果。
					// 但是不用担心路线会重叠，因为抵达终点所需要的更长的步数的路线会撞到短步数路线
					// 即碰到(d[nx][ny]!= -1的情况)

				}
			}
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1;i <= n;i++)
		for (int j = 1;j <= n;j++) {
			cin >> m[i][j];
		}
	cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs() << endl;
	return 0;
}