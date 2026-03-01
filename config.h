#ifndef CONFIG_H
#define CONFIG_H

#include <QVector>

//窗口长宽
#define WW 1600
#define WH 900
//格子大小
#define PX 80

//？？？
#define MA 4

// 格子数
extern int WB;
extern int HB;
// 地图位移和缩放比例
extern int BaseX;
extern int BaseY;
// 地图中存在障碍物的地方为 0b1，空格子为 0b0，其他数值为对应的矿物/设备
extern QVector<QVector<int>> gridMap; // 地图大小：12(y, 行)*20(x, 列)
extern int baseGridMap[20][32];
extern int mapSize[3][2];

#define MINER_IMG ":/img/img/Miner.png"
#define GRID_IMG ":/img/img/Grid.png"
#define BLOCK_IMG ":/img/img/Block.png"
#define SPLITTER_IMG ":/img/img/Splitter.png"
#define TRASH_IMG ":/img/img/Trash.png"
#define COMBINER_IMG ":/img/img/Combiner.png"
#define CONVEYOR_S_IMG ":/img/img/Conveyor.png"
#define CONVEYOR_T_IMG ":/img/img/ConveyorTurn.png"
#define CONVEYOR_PS_IMG ":/img/img/ConveyorPut.png"
#define CENTER_2x2_IMG ":/img/img/Center2x2.png"
#define CENTER_4x4_IMG ":/img/img/Center4x4.png"
#define BASE_IMG ":/img/img/Base.png"
#define ROUND_IMG ":/img/img/Round.png"
#define ROUND_MINE_IMG ":/img/img/RoundMine.png"
#define RECT_IMG ":/img/img/Rect.png"
#define RECT_MINE_IMG ":/img/img/RectMine.png"
#define BUBBLE_IMG ":/img/img/Bubble.png"
#define BUBBLE_MINE_IMG ":/img/img/BubbleMine.png"
#define MARK_IMG ":/img/img/ConveyorMark.png"
#define MINER_BTN ":/img/img/MinerButton.png"
#define SPLITTER_BTN ":/img/img/SplitterButton.png"
#define CONVEYOR_BTN ":/img/img/ConveyorButton.png"
#define COMBINER_BTN ":/img/img/CombinerButton.png"
#define RIGHT_ROTATE_BTN ":/img/img/RoaterRightButton.png"
#define TRASH_BTN ":/img/img/TrashButton.png"
#define ERASER_BTN ":/img/img/Eraser.png"
#define STORE_BTN ":/img/img/StoreButton.png"
#define PLAY_BTN ":/img/img/PlayButton.png"
#define PAUSE_BTN ":/img/img/PauseButton.png"
#define TIPS_BTN ":/img/img/TipsButton.png"
#define TOOLBAR ":/img/img/ToolBar.png"

// 定义当前进度
extern int reqCount, proCount;
// 定义每一关的分割点
extern QVector<int> proNum;
// 定义每一关需求
extern QVector<QPair<int, int>> demands;
// 定义地图等级、交付中心等级、矿产等级
extern int mapGrade, centerGrade, itemGrade;
extern int mapCost[3], centerCost[2], itemCost[3];
// 基础生成速度：帧/个，每帧为 10ms
extern int baseInterval;
// 传送带等级、采矿机等级、分割器和堆叠器等级
extern int conveyorGrade, minerGrade, splitterGrade;
// 定义游戏关卡进度、玩家拥有的金钱
extern int process, coin;
// 移动标记速度、生成速度
extern int markSpeed, markInterval;

#endif // CONFIG_H
