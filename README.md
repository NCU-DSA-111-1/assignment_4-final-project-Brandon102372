#How to compile
```
gcc -o ploytopia Map.c main.c linkedlist.c Entity.c coord.c
```
#How to execute
./ploytopia
#How to play
1.輸入要操作的座標
2.如果選擇自己的兵，輸入"M"會輸出當前士兵可行動的位置
	2.1.可以移動的位置以"O"表示，輸入對應位置座標士兵就會移動到該地，當前騎士的移動有問題，正在修
	2.2.可以攻擊的敵人以"X"表示，輸入對應位置座標士兵就會對該敵人造成傷害
3.在無人的己方村莊，輸入"T"可以生兵
	3.1.輸入"M"可以生成一般步兵
	3.2.輸入"s"可以生成一般騎士
