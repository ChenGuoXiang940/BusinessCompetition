# 商業類科技藝競賽程式設計 100-111
這是一個C++演算法實作與學習的項目。
> 本人工科畢業非參與商科競賽的選手，在大學前暑假期間抽空練習題目與留下筆記，盡可能的追求更好的執行效率，覺得不好讓人理解的地方會多補註解。參考資料：維基百科，自由的百科全書。並未實際評分，多少有錯誤之虞，以術科檢測資料測試 OK 才上傳。2023/08/08全部完成，每年大約12月會加入新題目。
## 圖（Graph）
## 為什麼要有圖？
- 實際運用：社交網絡中的朋友關係、城市之間的道路網絡、網絡拓撲、電子電路設計等等。
- 串列：根節點（Root）和下一個節點（Next）。
- 樹：根節點（Root）和葉子節點（Neighbor）。
- 圖：要多對多，就需要用到圖。
## 圖的基本介紹
- 兩個節點相連叫做邊。
- 節點的邊可以具有零個指向（NULL）或多個邊。
 ## 圖的常用概念
- 頂點（Vertex）
- 邊（Edge）
- 路徑（Path）
- 無向圖（Undirected Graph）
- 有向圖（Directed Graph）
- 帶權圖（Weighted Graph）
- 花費（Cost）或權重（Weight）
 ## 圖的表示方式
|   |名稱|組成|補充|
|:-:|:-:|:-:|:-:|
| 1 |鄰接矩陣（Adjacency Matrix）|二維整數陣列|每個元素代表各點之間是否有邊相連，用於**有向圖**|
| 2 |鄰接表（Adjacency List）|無序對映容器配 ArcNode 結構|每一個頂點相鄰的邊集的集合，用於[**無向圖**](https://github.com/chen199940/BusinessCompetition100-111#%E5%9C%96%E7%9A%84%E5%BB%BA%E7%AB%8B)|
| 3 |十字鏈結串列（Orthogonal Linked List）|二維 OLNode 結構|同時連結左右水平鄰結點與上下垂直鄰結點|
## 圖的搜尋演算法
- 深度優先搜尋（DFS）
- 廣度優先搜尋（BFS）
## 圖的建立
### **無向圖**
> E 代表輸入邊的數量，邊沒有方向只需知道 A 與 B 連接，不需知道儲存在哪個位置，用 unordered_map（無序容器）快速查找。
```cpp
#include<vector>
#include<unordered_map>
struct Data     //自定義的結構（struct）
{
   int val;      //表示節點的值
   vector<int>v;//存儲與節點相關的連接節點值的容器
   };
   int main(){
   unordered_map<int,Data>graph; //建立圖
   for(int j=0;j<E;j++){
       cin>>a>>b;
       graph[a].v.push_back(b);  //無向圖，需雙向
       graph[b].v.push_back(a);  //從節點 A 到節點 B 的邊，同時也可以從節點 B 到節點 A
   }
}
```
## 樹（Tree）
## 為什麼要有樹？
- 實際運用：家族關係、組織結構、文件系統等等。
- 延伸觀念：知道前序和中序可用遞迴推出後序。
## 樹的常用概念
- 節點（Node）
- 根（Root）
- 父（Parent）
- 孩（Degree）
- 深度（Depth）
- 高度（Height）
## 樹的建立
**二元樹**
```cpp
struct TreeNode    //自定義的結構（struct），用於表示二元樹中的節點。
{
   int val;        //表示節點的值
   TreeNode* left; //指向左子樹的指針，如果沒有左子樹，則為 nullptr
   TreeNode* right;//指向右子樹的指針，如果沒有右子樹，則為 nullptr
   TreeNode(int x):val(x),left(nullptr),right(nullptr){}//構造函數
};
```
## 資料結構
## 為什麼要有資料結構？
- 資料存放在記憶體中時，需要先將資料定義成最有利的抽象資料型態，讓程式能夠有效率地從**記憶體**中存取這些資料。
- 讓你更有效率地把資料存到電腦裡或取用，這裡的「效率」指的是節省空間（解決**空間複雜度**）或提升查找速度（解決**時間複雜度**）
- 演算法在時間與空間的優化取決於實際應用場景。在某些情況下，優化時間會導致增加額外空間。
## 常見的資料結構
- String
- 陣列（array）
- 結構（struct）
- vector
- stack
- queue
- map
- priority_queue
- unordered_map
- unordered_set
- bitset
