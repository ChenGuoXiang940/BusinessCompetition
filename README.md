# 商業類科技藝競賽程式設計100-111
## C++演算法實作與學習
> 本人工科畢業非參與商科競賽的選手，在大學前暑假期間抽空練習題目與留下筆記，盡可能的追求更好的執行效率，覺得不好讓人理解的地方會多補註解。
## 圖(Graph)
> ## 為什麼要有圖?
>> * 串列:根節點(root)和下一個節點(next)。
>> * 樹:根節點(root)和葉子節點(neighbor)。
>> * 圖:當我們需要多對多，就需要用到圖。
> ## 圖的基本介紹
>> * 兩個節點相連叫做邊。
>> * 節點的邊可以具有零個(指向NULL)或多個邊。
> ## 圖的常用概念
>> * 頂點(Vertex)
>> * 邊(Edge)
>> * 路徑(Path)
>> * 無向圖(Undirected Graph)
>> * 有向圖(Directed Graph)
>> * 帶權圖(Weighted Graph)
>> * 花費(cost)或權重(Weight)
> ## 圖的表示方式
>> * 鄰接矩陣（Adjacency Matrix）:二維陣列(int)
>> * 鄰接表（Adjacency List）:unordermap_set + struct(vector int + int) [請參考:圖的建立->無向圖](https://github.com/chen199940/BusinessCompetition100-111#%E5%9C%96%E7%9A%84%E5%BB%BA%E7%AB%8B)
>> * 十字連結串列（Cross Linked List）:含鄰接矩陣和鄰接表的特點，程式碼要建立類別跟結構=>很花時間，請少用
> ## 圖的搜尋演算法
>> * 深度優先搜尋(DFS) **迴圈+遞迴**
>> * 廣度優先搜尋(BFS) **迴圈+佇列Queue**
> ## 樹的建立
>> * **二元樹**<br>實際運用:家族關係、組織結構、文件系統等。<br>常用概念:node(節點)、root(根)、parent(父)、degree(孩)、depth(深度)、height(高度)
>> ```cpp
>> struct TreeNode    //自定義的結構（struct），用於表示二元樹中的節點。
>> {
>>    int val;        //表示節點的值
>>    TreeNode* left; //指向左子樹的指針，如果沒有左子樹，則為   nullptr
>>    TreeNode* right;//指向右子樹的指針，如果沒有右子樹，則為   nullptr
>>    TreeNode(int x):val(x),left(nullptr),right(nullptr){}//構造函數
>> };
>> ```
> ## 圖的建立
>> * **無向圖**<br>實際運用:社交網絡中的朋友關係、城市之間的道路網絡、網絡拓撲等。<br>程式說明:E代表輸入邊的數量，邊沒有方向只需知道a與b連接，不需知道儲存在哪個位置，用unordered_map(無序容器)快速查找。
>> ```cpp
>> #include<vector>
>> #include<unordered_map>
>> struct Data     //自定義的結構（struct）
>> {
>>   int val;      //表示節點的值
>>    vector<int>v;//存儲與節點相關的連接節點值的容器
>> };
>> int main(){
>>   unordered_map<int,Data>graph; //建立圖
>>   for(int j=0;j<E;j++){
>>       cin>>a>>b;
>>       graph[a].v.push_back(b);  //無向圖，需雙向
>>       graph[b].v.push_back(a);  //從節點a到節點b的邊，同時也可以從節點b到節點a
>>   }
>> }
>> ```
## 資料結構
> ## 為什麼要有資料結構?
>> * 資料存放在記憶體中時，需要先將資料定義成最有利的抽象資料型態，讓程式能夠有效率地從記憶體中存取這些資料。
>> * 讓你更有效率地把資料存到電腦裡或取用，這裡的「效率」指的是節省空間(解決空間複雜度)或提升查找速度(解決時間複雜度)
>> * 演算法在時間與空間的優化取決於具體的應用場景。在某些情況下，優化時間複雜度會導致增加空間複雜度。
> ## 常見的資料結構
>> * String
>> * 陣列
>> * vector
>> * map
>> * stack
>> * queue
>> * priority_queue
>> * unordered_map
