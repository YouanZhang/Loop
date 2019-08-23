# Loop

---

## 游戏玩法

---

游戏操作简单，上手容易，画风清新自然。

游戏中，玩家需要在杂乱无章的线条中，点击它们即可转换它们的朝向，以便在一定区域内形成回路。当场景中的所有线条都处在回路状态时玩家即可过关。

## 项目功能

---

1. 能够自动判定在每一步操作后是否达到要求过关。

2. 能够自动读档存档。

3. 能够自动生成每个关卡的地图，而且难度逐步提高。

## 开发技术

---

源代码使用QT5 + C++进行编写。
由于不建议使用数据库，故而采取文件读写。

## 模块设计

---

游戏开始时生成当前关卡，每个关卡由一个"Graph"构成。

每个"Graph"由n*m个"Corner"构成。其中"Corner"作为抽象类，派生出五个子类，分别代表每个格子的样式。

## 后续完善

---

介于时间和技术等因素，目前还有许多预想的功能未能实现。

1. 背景音乐功能
2. 排行榜功能
3. 存档功能不完善（目前暂支持一个存档）
