#include "sanjuan.h"

const string invalidtext[2] = {"Invalid Option", "錯誤選項"};
const string cardNameData[2][30] = 
    {{"\033[0;35mIndigo plant\033[0m", "\033[0;33mSugar Mill\033[0m", "\033[0;32mTobacco storage\033[0m",
    "\033[0;34mCoffee Roaster\033[0m", "\033[0;36mSilver smelter\033[0m",
    "Tower", "Chapel", "Smithy", "Poor House", "Black Market", "Crane", "Carpenter",
    "Quarry", "Well", "Aqueduct", "Market Stand", "Market Hall", "Trading Post", "Archive",
    "Perfecture", "Gold mine", "Library", "Statue", "Victory Column", "Hero", "Guild Hall", "City Hall",
    "Triumhal Arch", "Palace"},
    {"\033[0;35m染料廠\033[0m", "\033[0;33m蔗糖廠\033[0m", "\033[0;32m菸草廠\033[0m", "\033[0;34m咖啡廠\033[0m", "\033[0;36m白銀廠\033[0m", "塔樓", "禮拜堂", "鐵匠鋪", "救濟院",
    "黑市", "起重機", "木工場", "採石場", "水井", "溝渠", "攤販", "市場", "交易所", "檔案館", "辦公處", "金礦坑", "圖書館",
    "雕鑄像紀念碑", "勝利柱紀念碑", "英雄像紀念碑", "同業會館", "市政廳", "凱旋門", "宮殿"}};
const string botactiontext[2] = {"Bot Action", "電腦回合"};


const string roleName[2][5] = {{"Builder", "Producer", "Trader", "Councilor", "Prosoector"}, {"建築師", "生產者", "商人", "市長", "淘金者"}};
const string roleDescription[2][5] = {{"Action\nStart from governor's left,clock wise.Player can choose to build a building and pay the card cost\n\nPrivilege\nGovernor can pay 1 less of the cost. The final cost can't lower than 1 cost.\n",
                                        "Action\nStart from governor's left,clock wise.Player can choose produce 1 product.\n\nPrivilege\nGovernor can product an extra product.\n",
                                        "Action\nStart from governor's left,clock wise.Player can sell 1 product.\n\nPrivilege\nGovernor can sell an extra product.\n\nFlip 1 price list.\nThe product's value depents on the list.\n",
                                        "Action\nStart from governor's left,clock wise.Player can draw 2 cards and keep one.\n\nPrivilege\nGovernor can draw 5 cards and keep one\n",
                                        "Action\nNone.\n\nPrivilege\nGovernor can draw 1 card.\n"},
                                        {"行動\n從總督左邊開始，順時鐘方向，玩家選擇1張欲建造的建築卡，並支付卡片費用。\n\n特權\n總督在建造時，可以少支付1個費用，但最後的費用不能少於1。\n",
                                        "行動\n從總督左邊開始，順時鐘方向，玩家可以生產1個貨品。\n\n特權\n總督可以多生產1個貨品。\n",
                                        "行動\n從總督左邊開始，順時鐘方向，玩家可以販賣1個貨品。\n\n特權\n總督可以多販賣1個貨品。\n\n翻開1張價目表，貨品價格依照價目表決定。\n",
                                        "行動\n從總督左邊開始，順時鐘方向，玩家抽2張牌選擇1張留著。\n\n特權\n總督可以抽5張牌並選擇1張留著。\n",
                                        "行動\n無。\n\n特權\n總督可以抽1張牌。\n"}};
const string cardDescription[2][30] = {{"\nproducer phase\nowner produces 1 indigo\n",
                                        "\nproducer phase\nowner produces 1 sugar\n",
                                        "\nproducer phase\nowner produces 1 tobacco\n",
                                        "\nproducer phase\nowner produces 1 coffee\n",
                                        "\nproducer phase\nowner produces 1 silver\n",
                                        "\nbeginning of a round\nwhen the governor checks players’ hands for the card limit of 7,\na player with a towerhasa hand limit of 12 instead of 7.\nOf course, if the owner of a tower has more than 12 cards at the\nbeginning of a round,he must discard all cards over 12 to the discard stack.\n",
                                        "\nbeginning of a round\nbefore the governor checks the players’ card limits(of 7 or 12),\nthe owner of a chapel may place any one of his hand cards\nface down under the chapel. At game end, the player scores 1 victory point for each card under his chapel.\n",
                                        "\nbuilder phase\nWhen the owner of a smithy builds a production building, he may pay one\ncard less to build it. When a player builds a violet building,\nhe gets no advantage from a smithy.\n",
                                        "\nbuilder phase\nAfter the owner of a poor house has built a building, he may draw 1 card\nfrom the card supply, adding it to his hand, if he has only 0\nor 1 card in his hand.\n",
                                        "\nbuilder phase\nWhen the owner of a black market builds any building,he may use up to 2 of\nhis goods(from his production buildings) instead of cards from\nhis hand, placing them face down on the discard stack just\nlike cards from his hand.\n",
                                        "\nbuilder phase\nThe owner of a crane may overbuild any of his existing buildings, placing the\nnew building card completely covering the old card. By doing\nso, he reduces the cost of the new building by the cost of\nthe old building.\n",
                                        "\nbuilder phase\nAfter the owner of a carpenter builds a violet building and paysthe buildingcost,\nhe may draw 1 card from the cardsupply and add it to his hand.\nThe carpenter has no special function when the player\nbuilds a production building.\n",
                                        "\nbuilder phase\nWhen the owner of a quarry builds a violet building, he pays 1 card less to build\nthe building.The quarry has no special function when the player\nbuilds a production building.\n",
                                        "\nproducer phase\nIn the producer phase, if the owner of a well produces at least 2 goods, he draws an additional card from\nthe cardsupply, adding it to hishand. It matters not whether he\nis the producer or not.\n",
                                        "\nproducer phase\nIn the producer phase, the owner of an aquaduct may produce 1 more good than otherwise possible\n",
                                        "\ntrader phase\nDuring the trader phase, if the owner of a market stand sells at least 2 goods,\nhe draws an additional card from the cardsupply, adding it to his hand.\nIt matters not whether he is the trader or not.\n",
                                        "\ntrader phase\nWhen the owner of a market hall sells at least one good,he draws 1 card more than\nthe price of the good sold from the card supply. If he sells more than 1 good,\nhe only draws one extra card, not 1 extra\ncard for each good sold.\n",
                                        "\ntrader phase\nDuring the trader phase, the owner of a trading post may sell 1 additional good from\nhis production buildings.\n",
                                        "\ncouncillor phase\nWhen any player selects the councillor role, the owner of an archive adds all cards\nhe draws to his hand and then chooses which cards to discard from his entire hand.\nIn other words,the player may discard drawn cards or cards he\nalready had in his hand instead of just drawn cards.\n",
                                        "\ncouncillor phase\nIn the councillor phase, the owner of a prefecture may keep 2 cards instead of 1\n",
                                        "\nprospector phase\nAfter a player selects the prospector role and takes the privilege (or not),\neach player who owns a gold mine, in clockwise order,may turn over\nthe top-most 4 cards from the card supply, placing them face up on the table:\n• if all four cards have different building costs,\nthe player adds any one of the cards to his hand and discards the other 3 cards face down on the discard stack.\n• if at least 2 of the cards have the same building cost, the player gets no card\nand discards all 4 cards face down onthe discard stack.\n",
                                        "\nall phases\nThe owner of a library may double the privilege of the role he selects.\n",
                                        "\nMomument\nNo special effect.\n",
                                        "\nMomument\nNo special effect.\n",
                                        "\nMomument\nNo special effect.\n",
                                        "\ngame end\nAt game end, the owner of a guild hall scores 2 victory points for each production building\nin his play area.\n",
                                        "\ngame end\nAt game end, the owner of a city hall scores 1 victory point for each violet building\nin his play area.\n",
                                        "\ngame end\nAt game end, the owner of a triumphal arch scores victory points(VP) for the monuments\nin hisplay area: for 1 monument he scores 4 VP, for 2 monument she scores 6 VP,\nand for 3 monuments he scores 8 VP.\n",
                                        "\ngame end\nAt game end, the owner of a palace scores an extra 1/4 of his victory points\n"},
                                        {"\nproducer phase\nowner produces 1 indigo\n",
                                        "\nproducer phase\nowner produces 1 sugar\n",
                                        "\nproducer phase\nowner produces 1 tobacco\n",
                                        "\nproducer phase\nowner produces 1 coffee\n",
                                        "\nproducer phase\nowner produces 1 silver\n",
                                        "\nbeginning of a round\nwhen the governor checks players’ hands for the card limit of 7,\na player with a towerhasa hand limit of 12 instead of 7.\nOf course, if the owner of a tower has more than 12 cards at the\nbeginning of a round,he must discard all cards over 12 to the discard stack.\n",
                                        "\nbeginning of a round\nbefore the governor checks the players’ card limits(of 7 or 12),\nthe owner of a chapel may place any one of his hand cards\nface down under the chapel. At game end, the player scores 1 victory point for each card under his chapel.\n",
                                        "\nbuilder phase\nWhen the owner of a smithy builds a production building, he may pay one\ncard less to build it. When a player builds a violet building,\nhe gets no advantage from a smithy.\n",
                                        "\nbuilder phase\nAfter the owner of a poor house has built a building, he may draw 1 card\nfrom the card supply, adding it to his hand, if he has only 0\nor 1 card in his hand.\n",
                                        "\nbuilder phase\nWhen the owner of a black market builds any building,he may use up to 2 of\nhis goods(from his production buildings) instead of cards from\nhis hand, placing them face down on the discard stack just\nlike cards from his hand.\n",
                                        "\nbuilder phase\nThe owner of a crane may overbuild any of his existing buildings, placing the\nnew building card completely covering the old card. By doing\nso, he reduces the cost of the new building by the cost of\nthe old building.\n",
                                        "\nbuilder phase\nAfter the owner of a carpenter builds a violet building and paysthe buildingcost,\nhe may draw 1 card from the cardsupply and add it to his hand.\nThe carpenter has no special function when the player\nbuilds a production building.\n",
                                        "\nbuilder phase\nWhen the owner of a quarry builds a violet building, he pays 1 card less to build\nthe building.The quarry has no special function when the player\nbuilds a production building.\n",
                                        "\nproducer phase\nIn the producer phase, if the owner of a well produces at least 2 goods, he draws an additional card from\nthe cardsupply, adding it to hishand. It matters not whether he\nis the producer or not.\n",
                                        "\nproducer phase\nIn the producer phase, the owner of an aquaduct may produce 1 more good than otherwise possible\n",
                                        "\ntrader phase\nDuring the trader phase, if the owner of a market stand sells at least 2 goods,\nhe draws an additional card from the cardsupply, adding it to his hand.\nIt matters not whether he is the trader or not.\n",
                                        "\ntrader phase\nWhen the owner of a market hall sells at least one good,he draws 1 card more than\nthe price of the good sold from the card supply. If he sells more than 1 good,\nhe only draws one extra card, not 1 extra\ncard for each good sold.\n",
                                        "\ntrader phase\nDuring the trader phase, the owner of a trading post may sell 1 additional good from\nhis production buildings.\n",
                                        "\ncouncillor phase\nWhen any player selects the councillor role, the owner of an archive adds all cards\nhe draws to his hand and then chooses which cards to discard from his entire hand.\nIn other words,the player may discard drawn cards or cards he\nalready had in his hand instead of just drawn cards.\n",
                                        "\ncouncillor phase\nIn the councillor phase, the owner of a prefecture may keep 2 cards instead of 1\n",
                                        "\nprospector phase\nAfter a player selects the prospector role and takes the privilege (or not),\neach player who owns a gold mine, in clockwise order,may turn over\nthe top-most 4 cards from the card supply, placing them face up on the table:\n• if all four cards have different building costs,\nthe player adds any one of the cards to his hand and discards the other 3 cards face down on the discard stack.\n• if at least 2 of the cards have the same building cost, the player gets no card\nand discards all 4 cards face down onthe discard stack.\n",
                                        "\nall phases\nThe owner of a library may double the privilege of the role he selects.\n",
                                        "\nMomument\nNo special effect.\n",
                                        "\nMomument\nNo special effect.\n",
                                        "\nMomument\nNo special effect.\n",
                                        "\ngame end\nAt game end, the owner of a guild hall scores 2 victory points for each production building\nin his play area.\n",
                                        "\ngame end\nAt game end, the owner of a city hall scores 1 victory point for each violet building\nin his play area.\n",
                                        "\ngame end\nAt game end, the owner of a triumphal arch scores victory points(VP) for the monuments\nin hisplay area: for 1 monument he scores 4 VP, for 2 monument she scores 6 VP,\nand for 3 monuments he scores 8 VP.\n",
                                        "\ngame end\nAt game end, the owner of a palace scores an extra 1/4 of his victory points\n"}};

/* 
Card List:
Indigo plant 染料廠, Sugar Mill 蔗糖廠, Tobacco storage 菸草廠, Coffee Roaster 咖啡廠, Silver smelter 白銀廠,
Tower 塔樓(✔), Chapel 禮拜堂, Smithy 鐵匠鋪(✔), Poor House 救濟院(✔), Black Market 黑市(✔, lazy),
Crane 起重機, Carpenter 木工場(✔), Quarry 採石場(✔), Well 水井(✔), Aqueduct 溝渠(✔),
Market Stand 攤販(✔), Market Hall 市場(✔),, Trading Post 交易所(✔), Archive 檔案館, Perfecture 辦公處(✔), 
Gold mine 金礦坑(✔), Library 圖書館, Statue 雕鑄像紀念碑, Victory Column 勝利柱紀念碑, Hero 英雄像紀念碑,
Guild Hall 同業會館, City Hall 市政廳, Triumhal Arch 凱旋門, Palace 宮殿
*/

const u8 initcardCounts[] = {10, 8, 8, 8, 8, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2};
const u8 vp[] = {1, 1, 2, 2, 3, 2, 2, 1, 1, 1, 1, 2, 2, 1, 2, 1, 2, 1, 1, 2, 1, 3, 3, 4, 5, 0, 0, 0, 0};
const u8 type[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2};
const u8 phase[] = {3, 3, 3, 3, 3, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 6, 7, 8, 8, 8, 9, 9, 9, 9};
const u8 cost[] = {1, 2, 3, 4, 5, 3, 3, 1, 2, 2, 2, 3, 4, 2, 3, 2, 4, 2, 1, 3, 1, 5, 3, 4, 5, 6, 6, 6, 6};
const u8 priceList[5][5] = {{1, 1, 2, 2, 3},
                            {1, 2, 2, 2, 3},
                            {1, 1, 2, 2, 2},
                            {1, 2, 2, 3, 3},
                            {1, 1, 1, 2, 2}};

int cardCounts[29] = {0};
int discardcard[29] = {0};
int language = 0;
int gameover = 0;
int players = 4;

const player player_init = {
    .buildings = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    .hasgoods = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    .deck = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    .builds = 0,
    .cards = 0,
    .maxcard = 7,
    .isbot = 1
};

player *p;

//print beautiful banner :)
void printbanner(){ 
        printf("=============================================\n");
        setcolor(YEL);
        printf(" ____                    _                    \n");
        printf("/ ___|  __ _ _ __       | |_   _  __ _ _ __  \n");
        printf("\\___ \\ / _` | '_ \\   _  | | | | |/ _` | '_ \\ \n");
        printf(" ___) | (_| | | | | | |_| | |_| | (_| | | | |\n");
        printf("|____/ \\__,_|_| |_|  \\___/ \\__,_|\\__,_|_| |_|\n");
        setcolor(RESET);
        printf("                            Made By 40947029S\n");
        printf("=============================================\n");
}

//Print Mainmenu
int mainmenu(){ 
    const string menutext[2] = {"(1)Start Game    (2)Set Language    (3)Exit", "(1)開始遊戲    (2)設定語言    (3)離開"};
    int rt = 0,invalid = 0;
    while(rt < 1 || rt > 3){
        CLEAR
        printbanner();
        printf("%s\n\n", menutext[language]);
        if(invalid) INVALID
        printf("Choice: ");
        scanf("%d", &rt);
        FLUSH
        if(rt < 1 || rt > 3){
            invalid = 1;
        }
    }
    return rt;
}

//check gameover
void isgameover(){
    for(int i=0; i<players; i++){
        if(p[i].builds == 12){
            gameover = 1;
        }
    }
}

//Set Language
void setlanguage(){
    int rt = 0,invalid = 0;
    while(rt < 1 || rt > 2){
        CLEAR
        printbanner();
        printf("Set Language    設定語言\n");
        printf("(1) English    (2) 中文\n\n");
        if(invalid) INVALID
        printf("Choice: ");
        scanf("%d", &rt);
        FLUSH
        if(rt < 1 || rt > 2){
            invalid = 1;
        }
    }
    language = rt-1;
}

//generate random card
int randomcard(){ 
    int rt = rand() % 29;
    while(cardCounts[rt] == 0){
        rt = rand() % 29;
    }
    cardCounts[rt]--;
    return rt;
}

//game start init
void game_start(int players){ 
    int choice = 0, invalid = 0;
    p = calloc(4,sizeof(players));
    for(int i=0 ;i<29; i++){
        cardCounts[i] = initcardCounts[i];
    }
    cardCounts[0] -= players;
    for(int i=0; i<players; i++){
        p[i] = player_init;
        p[i].builds = 1;
        p[i].buildings[0] = 0;
        for(int j=0; j<4; j++){
            p[i].deck[j] = randomcard(cardCounts);
            p[i].cards++;
        }
        printf("%d\n", p[i].hasgoods[1]);
    }
    p[0].isbot = 0;
    main_game(players);
}

//Main game
void main_game(int playersarg){
    players = playersarg;
    int governor = rand() % players;
    while(!gameover){
        int choserole[5] = {0,0,0,0,0};
        int playernow = governor;
        int count = players;
        while(count--){
            int role;
            if(p[playernow].isbot == 1){    //Select role bot action
                while(1){
                    role = rand() % 5;
                    if(choserole[role] == 0){
                        break;
                    }
                }
                CLEAR
                if(language == 0){
                    printf("Player %d chose %s\n",playernow+1, roleName[language][role]);
                }else{
                    printf("玩家 %d 選擇 %s\n",playernow+1, roleName[language][role]);
                }
                PAUSE
                CLEAR
            }else{      //Select role player action
                int invalid = 0;
                checkstat(playernow);
                while(1){
                    CLEAR
                    if(language == 0){          
                        printf("Please Choose a role:\n ");
                    }else{
                        printf("請選擇職業:\n ");
                    }
                    for(int i=0; i<5; i++){
                        if(choserole[i] == 0){
                            printf("(%d) %s  ", i+1, roleName[language][i]);
                        }
                    }
                    printf("\n");
                    if(invalid) INVALID
                    printf("Choice: ");
                    scanf("%d", &role);
                    FLUSH
                    role--;
                    if(role < 0 || role > 4 || choserole[role] == 1){
                        invalid = 1;
                    }else{
                        break;
                    }
                }
            }
            choserole[role] = 1;

            //Call each role's function
            switch(role){
                case 0:
                    builder(playernow);
                    break;
                case 1:
                    producer(playernow);
                    break;
                case 2:
                    trader(playernow);
                    break;
                case 3:
                    councilor(playernow);
                    break;
                case 4:
                    prospector(playernow);
                    break;
            }
            playernow++;
            if(playernow == 4){
                playernow = 0;
            }
        }
        governor++;
        if(governor == 4){
            governor = 0;
        }
    }
}

int checkbuilding(int playernum, int cardnum){
    int rt = 0;
    for(int i=0; i<p[playernum].builds; i++){
        if(p[playernum].buildings[i] == cardnum){
            rt = 1;
            break;
        }
    }
    return rt;
}

//print all player stats
void checkstat(int playernow){
    CLEAR
    for(int i=0; i<players; i++){
        printf("=============================\n");
        if(language == 0){
            printf("Player %d's Building:\n", i+1);
        }else{
            printf("玩家 %d 的建築:\n", i+1);
        }
        for(int j=0; j<p[i].builds; j++){
            printf("(%d) %s ", j+1, cardNameData[language][p[i].buildings[j]]);
            if(p[i].hasgoods[j] != -1){
                if(language == 0){
                    setcolor(GRN_BACK);
                    printf("(Has good)");
                    setcolor(RESET);
                }else{
                    setcolor(GRN_BACK);
                    printf("(有資源)");
                    setcolor(RESET);
                }
            }
            printf("\n");
        }
    }
    printf("=============================\n");
    if(language == 0){
        printf("Your hand:\n");
    }else{
        printf("你的手牌:\n");
    }
    for(int i=0; i<p[playernow].cards; i++){
        printf("(%d) %s\n", i+1, cardNameData[language][p[playernow].deck[i]]);
    }
    printf("=============================\n");
    PAUSE
}

//Print player's hand
void printdeck(int playernum){
    const string printdecktext[2] = {"There is no card", "沒有手牌"};
    for(int i=0; i<p[playernum].cards; i++){
        printf("(%d) %s Cost:%u VP:%u\n", i+1, cardNameData[language][p[playernum].deck[i]], cost[p[playernum].deck[i]] , vp[p[playernum].deck[i]]);
    }
    if(p[playernum].cards == 0){
        setcolor(RED_BACK);
        printf("%s\n", printdecktext[language]);
        setcolor(RESET);
    }
}

//print player's buildings
void printbuilding(int playernum){
    for(int i=0; i<p[playernum].builds; i++){
        printf("(%d) %s goods:%d\n", i+1, cardNameData[language][p[playernum].buildings[i]], p[playernum].hasgoods[i]);
    }
}

//rebuild player's hand
void rebuilddeck(int playernum){
    //printf("Rebuilding...");
    int tmp[12] = {-1},tmpcards = 0;
    for(int i=0; i<p[playernum].cards; i++){

        if(p[playernum].deck[i] != -1){
            tmp[tmpcards] = p[playernum].deck[i];
            tmpcards++;
        }
    }
    for(int i=0; i<12; i++){
        p[playernum].deck[i] = tmp[i];
    }
    p[playernum].cards = tmpcards;
    //printf("Success\n");
}

//discard card from player's hand
void playerdiscard(int playernum, int cardpos){
    discardcard[p[playernum].deck[cardpos]]++;
    p[playernum].deck[cardpos] = -1;
    rebuilddeck(playernum);
}

//builderphase
void builder(int privilege){
    //printf("Builder Phase\n");
    //PAUSE
    const string buildertext[2][7] = {{"Skip Build", "Build", "Select A Card to Discard", "Not Enough Card to Pay The Cost", "You chose to build", "You skipped this round", "You can't build a duplicate non-production building"},
                                       "跳過", "建蓋", "選擇一張卡丟棄", "不夠支付該卡的花費", "你選擇建蓋", "你跳過了此回合", "你無法建造重複的非生產建築"};

    int playernow = privilege;
    int count = players;
    while(count--){
        if(p[playernow].isbot == 0){
            int choice, invalid = 0, costinvalid = 0, duplicate= 0;
            int costcount;
            int reducecost = 0;
            int tmpbuilding = -1;
            if(playernow == privilege){
                reducecost++;
            }
            while(1){   //Let user select card to build
                CLEAR
                printf("=============================\n");
                printdeck(playernow);
                printf("=============================\n");
                printf("(0)%s ", buildertext[language][0]);
                if(p[playernow].cards > 0){
                    printf("(1-%d)%s", p[playernow].cards, buildertext[language][1]);
                }
                printf("\n\n");
                if(invalid) INVALID
                if(costinvalid) printf("%s%s%s\n",RED_BACK, buildertext[language][3],RESET);
                if(duplicate) printf("%s%s%s\n",RED_BACK, buildertext[language][6],RESET);
                printf("Choice:");
                scanf("%d", &choice);
                FLUSH
                invalid = 0;
                costinvalid = 0;
                duplicate = 0;
                if(choice < 0 || choice > p[playernow].cards){  //check for invalid input
                    invalid = 1;
                }else if(choice != 0 && cost[p[playernow].deck[choice-1]]-reducecost > p[playernow].cards-1){
                    costinvalid = 1;
                }else if(choice != 0 && type[p[playernow].deck[choice-1]] != 0){
                    if(checkbuilding(playernow, p[playernow].deck[choice-1])){
                        duplicate = 1;
                    }
                }else if(choice != 0){
                    tmpbuilding = p[playernow].deck[choice-1];
                    reducecost += smithy(playernow, tmpbuilding) + quarry(playernow, tmpbuilding);
                    costcount = cost[p[playernow].deck[choice-1]]-reducecost;
                    p[playernow].buildings[p[playernow].builds] = p[playernow].deck[choice-1];
                    p[playernow].builds++;
                    reducecost += blackmarket(playernow, costcount);
                    costcount = cost[p[playernow].deck[choice-1]]-reducecost;
                    isgameover();
                    p[playernow].deck[choice-1] = -1;
                    rebuilddeck(playernow);
                    invalid = 0;
                    break;
                }else{
                    break;
                }
            }
            if(choice != 0){    //Discard cards to build
                printf("\n=============================\n");
                printf("%s %s\n", buildertext[language][4], cardNameData[language][tmpbuilding]);
                PAUSE
                int tmp = 1;
                while(tmp <= costcount){
                    while(1){
                        CLEAR
                        printf("=============================\n");
                        printdeck(playernow);
                        printf("=============================\n");
                        printf("%s (%d/%d)\n", buildertext[language][2], tmp, costcount);
                        if(invalid) INVALID
                        printf("Choice: ");
                        scanf("%d", &choice);
                        FLUSH
                        if(choice < 0 || choice > p[playernow].cards){
                            invalid = 1;
                        }else{
                            break;
                        }
                    }
                    playerdiscard(playernow, choice-1);
                    tmp++;
                }
                poorhouse(playernow);
                tower(playernow, tmpbuilding);
                carpenter(playernow, tmpbuilding);
            }else{
                printf("\n=============================\n");
                printf("%s\n", buildertext[language][5]);
                PAUSE
            }
        }else{
            CLEAR
            setcolor(CYN);
            printf("%s\n", botactiontext[language]);
            setcolor(RESET);
            printf("=============================\n");
            int botbuild = rand() % 2;
            int built = 0;
            int reducecost = 0;
            int builtbuilding;
            int avaliable[p[playernow].cards];
            int avaliablenum = 0;
            if(playernow == privilege){
                reducecost++;
            }
            if(botbuild){
                for(int i=0; i<p[playernow].cards; i++){    //check which cards are buildable
                    if(cost[p[playernow].deck[i]]-reducecost <= p[playernow].cards-1){
                        avaliable[avaliablenum] = i;
                        avaliablenum++;
                    }
                }
                if(avaliablenum != 0){  //choose which card to build
                    int choice = rand() % avaliablenum;
                    choice = avaliable[choice];
                    builtbuilding = p[playernow].deck[choice];
                    reducecost += smithy(playernow, builtbuilding) + quarry(playernow, builtbuilding);
                    int costcount = cost[p[playernow].deck[choice]]-reducecost;
                    p[playernow].buildings[p[playernow].builds] = builtbuilding;
                    p[playernow].builds++;
                    isgameover();
                    p[playernow].deck[choice] = -1;
                    rebuilddeck(playernow);
                    if(costcount == p[playernow].cards){
                        for(int i=0 ;i<p[playernow].cards ;i++){
                            p[playernow].deck[i] = -1;
                        }
                        p[playernow].cards = 0;
                        built = 1;
                    }else{
                        while(costcount--){
                            while(1){
                                int discard = rand() % p[playernow].cards;
                                if(p[playernow].deck[discard] != -1){
                                    p[playernow].deck[discard] = -1;
                                    playerdiscard(playernow, discard);
                                    break;
                                }
                            }
                        }
                        built = 1;
                        poorhouse(playernow);
                        tower(playernow, builtbuilding);
                        carpenter(playernow, builtbuilding);
                    }
                }
            }
            if(!built){
                if(language == 0){
                    printf("Player %d Skipped\n", playernow+1);
                }else{
                    printf("玩家 %d 跳過\n", playernow+1);
                }
            }else{
                if(language == 0){
                    printf("Player %d Built %s\n", playernow+1, cardNameData[language][builtbuilding]);
                }else{
                    printf("玩家 %d 建蓋 %s\n", playernow+1, cardNameData[language][builtbuilding]);
                }
            }
            PAUSE
        }
        playernow++;
        if(playernow == players){
            playernow = 0;
        }
    }
}

//producer phase
void producer(int privilege){
    const string producertext[2][6] = {{"Skip Produce", "Produce", "You are unable to produce any goods", "Choose one production building to produce", "produced 1 good", "You skipped this produce phase"},
                                       "跳過", "生產", "你無法進行任何生產", "選擇任一生產建築進行生產", "產出一份資源", "你跳過了此次生產"};

    
    int playernow = privilege;
    int count = players;

    while(count--){
        int producecount = 1;
        int produceable = 0;
        int producebuilding[12] = {-1};
        int produced = 0;
        if(playernow == privilege){
            producecount++;
        }
        producecount += aqueduct(playernow);
        if(p[playernow].isbot == 0){
            for(int i=0; i<p[playernow].builds; i++){
                if(type[p[playernow].buildings[i]] == 0 && p[playernow].hasgoods[i] == -1){
                    producebuilding[produceable] = i;
                    produceable++;
                }
            }
            if(produceable < producecount){
                producecount = produceable;
            }
            int tmptotal = producecount, tmpcount = 1;
            if(produceable){
                
                while(producecount--){
                    int choice = -1, invalid = 0;
                    //User enter produce choice
                    while(1){   
                        CLEAR
                        printf("=============================\n");
                        for(int i=0; i<produceable; i++){
                            printf("(%d) %s\n", i+1, cardNameData[language][p[playernow].buildings[producebuilding[i]]]);
                        }
                        printf("=============================\n");
                        printf("%s (%d/%d)\n", producertext[language][3], tmpcount, tmptotal);
                        printf("(0)%s (1-%d)%s\n\n", producertext[language][0], produceable, producertext[language][1]);
                        if(invalid) INVALID
                        printf("Choice: ");
                        scanf("%d", &choice);
                        FLUSH
                        if(choice < 0 || choice > produceable){
                            invalid = 1;
                        }else{
                            break;
                        }
                    }
                    //produce: get randomcard or skip
                    if(choice){
                        //get supply
                        produced++;
                        choice--;
                        p[playernow].hasgoods[producebuilding[choice]] = randomcard();
                        discardcard[p[playernow].hasgoods[producebuilding[choice]]]++;
                        produceable = 0;
                        printf("\n=============================\n");
                        printf("%s %s\n", cardNameData[language][p[playernow].buildings[producebuilding[choice]]], producertext[language][4]);
                        PAUSE
                        for(int i=0 ; i<12; i++){
                            producebuilding[i] = -1;
                        }
                        for(int i=0; i<p[playernow].builds; i++){
                            if(type[p[playernow].buildings[i]] == 0 && p[playernow].hasgoods[i] == -1){
                                producebuilding[produceable] = i;
                                produceable++;
                            }
                        }
                    }else{
                        //skipped produce
                        printf("\n=============================\n");
                        printf("%s\n", producertext[language][5]);
                    }

                    tmpcount++;
                }
            }else{
                CLEAR
                setcolor(RED_BACK);
                printf("%s\n", producertext[language][2]);
                setcolor(RESET);
                PAUSE
            }
        }else{
            CLEAR
            setcolor(CYN);
            printf("%s\n", botactiontext[language]);
            setcolor(RESET);
            printf("=============================\n");
            int isproduce = rand() % 2;
            for(int i=0; i<p[playernow].builds; i++){
                if(type[p[playernow].buildings[i]] == 0 && p[playernow].hasgoods[i] == -1){
                    producebuilding[produceable] = i;
                    produceable++;
                }
            }
            if(produceable < producecount){
                producecount = produceable;
            }
            if(isproduce && produceable){
                while(producecount--){
                    int choice = rand() % produceable;
                    p[playernow].hasgoods[producebuilding[choice]] = randomcard();
                    int tmpbuilding = producebuilding[choice];
                    produceable = 0;
                    produced++;
                    if(language == 0){
                        printf("Player %d's %s %s\n", playernow+1, cardNameData[language][p[playernow].buildings[tmpbuilding]], producertext[language][4]);
                    }else{
                        printf("玩家 %d 的 %s %s\n", playernow+1, cardNameData[language][p[playernow].buildings[tmpbuilding]], producertext[language][4]);
                    }
                    PAUSE
                    for(int i=0 ; i<12; i++){
                        producebuilding[i] = -1;
                    }
                    for(int i=0; i<p[playernow].builds; i++){
                        if(type[p[playernow].buildings[i]] == 0 && p[playernow].hasgoods[i] == -1){
                            producebuilding[produceable] = i;
                            produceable++;
                        }
                    }
                }
            }else{
                if(language == 0){
                    printf("Player %d skipped this round\n", playernow+1);
                }else{
                    printf("玩家 %d 跳過了此次生產\n", playernow+1);
                }
                PAUSE
            }
            
        }
        well(playernow, produced);
        playernow++;
        if(playernow == players){
            playernow = 0;
        }
        
    }
}

//trader phase
void trader(int privilege){
    const string tradertext[2][5] = {{"You don't have any goods to sell","Choose one good to sell","Skip","Sell Good","You skipped this round"},
                                      {"你沒有任何資源可供售出","選擇一項資源售出","跳過","賣出資源", "你跳過此回合"}};
    int playernow = privilege;
    int count = players;
    int pricecard = rand() % 5;
    while(count--){
        int tradecount = 1;
        int sellcount = 0;
        int goods[12] = {-1},sellable = 0;
        CLEAR
        printf("=============================\n\n");
        printf("        Price List :           \n");
        printf("        %s%d %s%d %s%d %s%d %s%d \n\n", MAG_BACK, priceList[pricecard][0],YEL_BACK, priceList[pricecard][1],GRN_BACK, priceList[pricecard][2],BLU_BACK, priceList[pricecard][3],CYN_BACK, priceList[pricecard][4]);
        setcolor(RESET);
        printf("=============================\n");        
        if(p[playernow].isbot == 0){    //User Action
            if(playernow == privilege){
                tradecount++;
            }
            tradecount += tradingpost(playernow);
            //check if player has card to sell
            for(int i=0; i<p[playernow].builds; i++){
                if(p[playernow].hasgoods[i] != -1){
                    goods[sellable] = i;
                    sellable++;
                }
            }
            if(sellable < tradecount){
                tradecount = sellable;
            }
            if(sellable){
                int choice, invalid = 0;
                while(tradecount){
                    for(int i=0; i<sellable; i++){
                        printf("(%d) %s\n", i+1, cardNameData[language][p[playernow].buildings[goods[i]]]);
                    }
                    printf("=============================\n");
                    printf("%s\n", tradertext[language][1]);
                    printf("(0) %s (1-%d) %s\n", tradertext[language][2], sellable, tradertext[language][3]);
                    printf("Choice: ");
                    scanf("%d", &choice);
                    FLUSH
                    if(choice < 0 || choice > sellable){
                        invalid = 1;
                        continue;
                    }else if(choice){
                        choice--;
                        sellcount++;
                        int producebuilding = p[playernow].buildings[goods[choice]];
                        p[playernow].hasgoods[goods[choice]] = -1;  //sell good
                        //Get supply
                        for(int i=0; i<priceList[pricecard][producebuilding]; i++){
                            p[playernow].deck[p[playernow].cards] = randomcard();
                            p[playernow].cards++;
                        }
                        if(language == 0){
                            printf("\n=============================\n");
                            printf("You sold good from %s and get %d ", cardNameData[language][producebuilding], priceList[pricecard][producebuilding]);
                            if(priceList[pricecard][producebuilding] == 1){
                                printf("supply\n");
                            }else{
                                printf("supplies\n");
                            }
                        }else{
                            printf("\n=============================\n");
                            printf("你在 %s 賣出了一份資源並且得到 %d 張手牌\n", cardNameData[language][producebuilding], priceList[pricecard][producebuilding]);
                        }
                        PAUSE
                        tradecount--;
                    }else{
                        printf("\n=============================\n");
                        printf("%s\n", tradertext[language][4]);
                        tradecount--;
                        PAUSE
                    }
                }

            }else{
                setcolor(RED_BACK);
                printf("%s\n", tradertext[language][0]);
                setcolor(RESET);
                PAUSE
                continue;
            }
            marketstand(playernow, sellcount);
            if(sellcount){
                markethall(playernow);
            }
        }else{                         //Bot action
            int botaction = rand() % 2;
            setcolor(CYN);
            printf("%s\n", botactiontext[language]);
            setcolor(RESET);
            printf("=============================\n");
            if(botaction){
                int sellcount = 0;
                if(playernow == privilege){
                    tradecount++;
                }
                tradecount += tradingpost(playernow);
                for(int i=0; i<p[playernow].builds; i++){
                    if(p[playernow].hasgoods[i] != -1){
                        goods[sellable] = i;
                        sellable++;
                    }
                }
                if(sellable < tradecount){
                    tradecount = sellable;
                }
                if(tradecount){
                    while(tradecount){
                        int choice = rand() % sellable;
                        int producebuilding = p[playernow].buildings[goods[choice]];
                        p[playernow].hasgoods[goods[choice]] = -1;  //sell good
                        //Get supply
                        for(int i=0; i<priceList[pricecard][producebuilding]; i++){
                            p[playernow].deck[p[playernow].cards] = randomcard();
                            p[playernow].cards++;
                        }
                        if(language == 0){
                            printf("Player %d sold good from %s and get %d ", playernow+1, cardNameData[language][producebuilding], priceList[pricecard][producebuilding]);
                            if(priceList[pricecard][producebuilding] == 1){
                                printf("supply\n");
                            }else{
                                printf("supplies\n");
                            }
                        }else{
                            printf("玩家 %d 在 %s 賣出了一份資源並且得到 %d 張手牌\n", playernow+1, cardNameData[language][producebuilding], priceList[pricecard][producebuilding]);
                        }
                        sellcount++;
                        tradecount--;
                        PAUSE
                    }
                }else{
                    if(language == 0){
                        printf("Player %d skipped this round\n", playernow+1);
                    }else{
                        printf("玩家 %d 跳過了此回合\n", playernow+1);
                    }
                    PAUSE 
                }
                marketstand(playernow, sellcount);
                markethall(playernow);
            }else{
                if(language == 0){
                    printf("Player %d skipped this round\n", playernow+1);
                }else{
                    printf("玩家 %d 跳過了此回合\n", playernow+1);
                }
                PAUSE
            }
            
        }
        playernow++;
        if(playernow == players){
            playernow = 0;
        }
    }
}

//councilor phase
void councilor(int privilege){
    const string councilortext[2][1] = {{"Choose a card to keep"},
                                         {"選擇保留其中一張卡"}};
    int playernow = privilege;
    int count = players;
    while(count--){
        int tmpcards[5] = {-1};
        int getcard = 2;
        int keepcard = 1;
        if(p[playernow].isbot == 0){
            if(playernow == privilege){
                getcard = 5;
            }
            keepcard += prefecture(playernow);
            for(int i=0; i<getcard; i++){
                tmpcards[i] = randomcard(); 
            }
            int keepcardcount = keepcard;
            int choice = 0, invalid = 0;
            while(keepcardcount){
                CLEAR
                printf("=============================\n"); 
                for(int i=0; i<getcard; i++){
                    printf("(%d) %s Cost:%u VP:%u\n", i+1, cardNameData[language][tmpcards[i]], cost[tmpcards[i]] , vp[tmpcards[i]]);
                }
                printf("=============================\n"); 
                printf("%s (%d/%d)\n", councilortext[language][0], keepcard - keepcardcount+1, keepcard);
                if(invalid) INVALID;
                printf("Choice: ");
                scanf("%d", &choice);
                FLUSH
                if(choice < 1 || choice > getcard){
                    invalid = 1;
                }else{
                    choice--;
                    p[playernow].deck[p[playernow].cards] = tmpcards[choice];
                    p[playernow].cards++;
                    keepcardcount--;
                    if(language == 0){
                        printf("\n=============================\n"); 
                        printf("You Chose %s to keep\n",cardNameData[language][tmpcards[choice]]);
                        PAUSE
                    }else{
                        printf("\n=============================\n"); 
                        printf("你選擇保留 %s\n",cardNameData[language][tmpcards[choice]]);
                        PAUSE
                    }
                    int tmparr[getcard-1];
                    int tmpcount = 0;
                    tmpcards[choice] = -1;
                    for(int i=0; i<getcard; i++){
                        if(tmpcards[i] != -1){
                            tmparr[tmpcount] = tmpcards[i];
                            tmpcount++;
                        }
                    }
                    getcard--;
                    for(int i=0; i<getcard; i++){
                        tmpcards[i] = tmparr[i];
                    }
                }
                for(int i=0; i<getcard; i++){
                    discardcard[tmpcards[i]]++;
                }
            }
        }else{
            if(playernow == privilege){
                getcard = 5;
            }
            for(int i=0; i<getcard; i++){
                tmpcards[i] = randomcard(); 
            }
            keepcard += prefecture(playernow);
            CLEAR
            setcolor(CYN);
            printf("%s\n", botactiontext[language]);
            setcolor(RESET);
            printf("=============================\n");
            if(language == 0){
                printf("Player %d got %d cards\n", playernow+1, keepcard);
            }else{
                printf("玩家 %d 保留了 %d 張卡\n", playernow+1, keepcard);
            }
            while(keepcard--){
                int choice = rand() % getcard;
                while(tmpcards[choice] == -1){
                    choice = rand() % getcard;
                }
                p[playernow].deck[p[playernow].cards] = tmpcards[choice];
                discardcard[tmpcards[choice]]++;
                p[playernow].cards++;
                tmpcards[choice] = -1;
            }
            int tmparr[getcard-1];
            int tmpcount = 0;
            for(int i=0; i<getcard; i++){
                if(tmpcards[i] != -1){
                    tmparr[tmpcount] = tmpcards[i];
                    tmpcount++;
                }
            }
            getcard = tmpcount;
            for(int i=0; i<getcard; i++){
                discardcard[tmpcards[i]]++;
            }
            PAUSE
        }
        playernow++;
        if(playernow == players){
            playernow = 0;
        }
    }
}

void prospector(int privilege){
    int playernow = privilege;
    int count = players;
    while(count--){
        if(playernow == privilege){
            int getcard = randomcard();
            p[playernow].deck[p[playernow].cards] = getcard;
            p[playernow].cards++;
            CLEAR
            if(p[playernow].isbot == 0){
                if(language == 0){
                    printf("Player %d got %s\n", playernow+1, cardNameData[language][getcard]);
                }else{
                    printf("玩家 %d 拿到了 %s\n", playernow+1, cardNameData[language][getcard]);
                }
            }else{
                if(language == 0){
                    printf("Player %d got one card\n", playernow+1);
                }else{
                    printf("玩家 %d 拿到了一張卡\n", playernow+1);
                }
            }
            PAUSE
        }
        playernow++;
        if(playernow = players){
            playernow = 0;
        }
    }
}

int smithy(int playernow, int builtbuilding){
    //Smithy 鐵匠鋪 (7)
    int rt = 0;
    if(type[builtbuilding] == 0 && checkbuilding(playernow, 7)){
        if(language == 0){
            printf("Use %ssmithy's%s ability, reduce production building cost by one.\n", GRN, RESET);
        }else{
            printf("發動 %s鐵匠鋪%s 能力, 減低一點製造建築的花費\n", GRN, RESET);
        }
        rt = 1;
    }
    return rt;
}

void tower(int playernow, int builtbuilding){
    //Tower 塔樓 (5)
    if(builtbuilding == 5){
        p[playernow].maxcard = 12;
        if(language == 0){
            printf("Use %stower's%s ability, increase max hand cards to 12.\n", GRN, RESET);
        }else{
            printf("發動 %s塔樓%s 能力, 手牌上限增加至12\n", GRN, RESET);
        }
    }
}

void poorhouse(int playernow){
    //Poor House 救濟院 (8)
    if(checkbuilding(playernow, 8)){
        if(p[playernow].cards <= 1){
            p[playernow].deck[p[playernow].cards] = randomcard();
            p[playernow].cards++;
            if(language == 0){
                printf("Use %spoor house's%s ability, get one card when there's one card or less left after building.\n", GRN, RESET);
            }else{
                printf("發動 %s救濟院%s 能力, 蓋完建築後若手牌剩下一張或以下可抽一張卡\n", GRN, RESET);
            }
        }
    }
}

int blackmarket(int playernow, int cost){
    //Black Market 黑市 (9)
    int rt = 0;
    if(checkbuilding(playernow, 9)){
        const string blackmarkettext[2][5] = {{"Do you want to use the ability?", "You chose not use the ability", "Select one good for deduction", "List of buildings that has good", "You skipped this deduction round"},
                                            {"你要使用這項能力嗎?", "你選擇不使用這項能力", "選擇一項資源來扣除花費", "有資源的建築列表", "你跳過了此次選擇機會"} };
        int goods[12] = {-1},sellable = 0;
        int playerhasgoods = 0;
        int choice = 0, invalid = 0;
        int maxcard = 2; 
        if(cost < maxcard){
            maxcard = cost;
        }
        for(int i=0; i<p[playernow].builds; i++){
            if(p[playernow].hasgoods[i] != -1){
                playerhasgoods = 1;
                goods[sellable] = i;
                sellable++;
            }
        }
        if(!playerhasgoods){
            return rt;
        }
        if(p[playernow].isbot == 0){
            while(1){
                CLEAR
                if(language == 0){
                    printf("Use %sblack market's%s ability, sell up to 2 good to reduce cost.\n", GRN, RESET);
                }else{
                    printf("發動 %s黑市%s 能力, 賣出至多兩份的資源來減少建蓋花費\n", GRN, RESET);
                }
                if(invalid) INVALID
                printf("%s\n(0)No (1)Yes\nChoice: ", blackmarkettext[language][0]);
                scanf("%d", &choice);
                if(choice < 0 || choice > 1){
                    invalid = 1;
                }else{
                    break;
                }
            }   
            if(choice){
                if(sellable < maxcard){
                    maxcard = sellable;
                }
                int totalmaxcard = maxcard;
                while(maxcard){
                    CLEAR
                    printf("%s\n", blackmarkettext[language][3]);
                    printf("=============================\n");
                    for(int i=0; i<sellable; i++){
                        printf("(%d) %s\n", i+1, cardNameData[language][p[playernow].buildings[goods[i]]]);
                    }
                    printf("=============================\n");
                    printf("%s (%d/%d)\n", blackmarkettext[language][2], totalmaxcard-maxcard+1, totalmaxcard);
                    if(invalid) INVALID
                    printf("(0)Skip (1-%d)Select Good\nChoice: ", sellable);
                    scanf("%d", &choice);
                    if(choice < 0 || choice > sellable){
                        invalid = 1;
                    }else if(choice){
                        maxcard--;
                        choice--;
                        rt++;
                        int tmpbuilding = goods[choice];
                        p[playernow].hasgoods[goods[choice]] = -1;
                        if(maxcard){
                            for(int i=0; i<p[playernow].builds; i++){
                                if(p[playernow].hasgoods[i] != -1){
                                    goods[sellable] = i;
                                    sellable++;
                                }
                            }
                        }
                        printf("=============================\n");
                        if(language == 0){
                            printf("You sell one good from %s and deduct one cost\n", cardNameData[language][p[playernow].buildings[tmpbuilding]]);
                        }else{
                            printf("你從 %s 賣出了一份資源並減少了一點花費\n", cardNameData[language][p[playernow].buildings[tmpbuilding]]);
                        }
                        PAUSE
                    }else{
                        maxcard--;
                        printf("=============================\n");
                        printf("%s\n", blackmarkettext[language][4]);
                        PAUSE
                    }
                }

            }else{
                printf("=============================\n");
                printf("%s\n", blackmarkettext[language][1]);
                PAUSE
            }
        }else{
            int useability = 0;
            CLEAR
            if(language == 0){
                printf("Use %sblack market's%s ability, sell up to 2 good to reduce cost.\n", GRN, RESET);
            }else{
                printf("發動 %s黑市%s 能力, 賣出至多兩份的資源來減少建蓋花費\n", GRN, RESET);
            }
            if(useability){
                //lazy (haven't implement)
            }else{
                printf("=============================\n");
                if(language == 0){
                    printf("Player %d chose not to use the ability.\n", playernow+1);
                }else{
                    printf("玩家 %d 選擇不使用能力\n", playernow+1);
                }
                PAUSE
            }
        }

    }

    return rt;
}

void carpenter(int playernow, int builtbuilding){
    //Carpenter 木工場 (11)
    if(type[builtbuilding] != 0 && checkbuilding(playernow, 11)){
        if(language == 0){
            printf("Use %scarpenter's%s ability, get an additional card when building an non-production building.\n", GRN, RESET);
        }else{
            printf("發動 %s木工廠%s 能力, 在建造非生產建築時可抽取一張卡\n", GRN, RESET);
        }
        p[playernow].deck[p[playernow].cards] = randomcard();
        p[playernow].cards++;
    }
}

int quarry(int playernow, int builtbuilding){
    //Quarry 採石場 (12)
    int rt = 0;
    if(type[builtbuilding] != 0 && checkbuilding(playernow, 11)){
        if(language == 0){
            printf("Use %squarry's%s ability, deduct one cost when building a non-prodution building.\n", GRN, RESET);
        }else{
            printf("發動 %s採石場%s 能力, 建造非生產建築時可減少一點花費\n", GRN, RESET);
        }
        rt = 1;
    }
    return rt;
}

void well(int playernow, int producecount){
    //Well 水井 (13)
    if(producecount >= 2 && checkbuilding(playernow, 13)){
        if(language == 0){
            printf("Use %swell's%s ability. If you produce more than two goods, you can get an additional card.\n", GRN, RESET);
        }else{
            printf("發動 %s採石場%s 能力, 當你生產兩個以上的資源,你可以額外抽取一張卡\n", GRN, RESET);
        }
        p[playernow].deck[p[playernow].cards] = randomcard();
        p[playernow].cards++;
    }
}

int aqueduct(int playernow){
    //Aqueduct 溝渠(14)
    int rt = 0;
    if(checkbuilding(playernow, 14)){
        if(language == 0){
            printf("Use %saqueduct's%s ability, you can produce one additional good.\n", GRN, RESET);
        }else{
            printf("發動 %s採石場%s 能力, 你可多額外生產一份資源\n", GRN, RESET);
        }
        rt = 1;
    }
    return rt;
}

void marketstand(int playernow, int sellcount){
    //Market Stand 攤販(15)
    if(sellcount >= 2 && checkbuilding(playernow, 15)){
        if(language == 0){
            printf("Use %smarket stand's%s ability, get one additional card when sold more than one goods.\n", GRN, RESET);
        }else{
            printf("發動 %s攤販%s 能力, 當賣出兩份以上資源時可額外獲得一張卡\n", GRN, RESET);
        }
        p[playernow].deck[p[playernow].cards] = randomcard();
        p[playernow].cards++;
    }
}

void markethall(int playernow){
    //Market Hall 市場 (16)
    if(checkbuilding(playernow, 16)){
        if(language == 0){
            printf("Use %smarket hall's%s ability, get one additional card after trader phase action.\n", GRN, RESET);
        }else{
            printf("發動 %s交易所%s 能力, 在商人階段行動完成後可額外獲得一張卡\n", GRN, RESET);
        }
        p[playernow].deck[p[playernow].cards] = randomcard();
        p[playernow].cards++;
    }
}

int tradingpost(int playernow){
    //Trading Post 交易所 (17)
    int rt = 0;
    if(checkbuilding(playernow, 17)){
        if(language == 0){
            printf("Use %strading post's%s ability, sell one additional good during trader phase.\n", GRN, RESET);
        }else{
            printf("發動 %s交易所%s 能力, 在商人階段可額外售出一份資源\n", GRN, RESET);
        }
        rt = 1;
    }
    return rt;
}

int prefecture(int playernow){
    //Perfecture 辦公處 (19)
    int rt = 0;
    if(checkbuilding(playernow, 19)){
        if(language == 0){
            printf("Use %sperdecture's%s ability, choose one additional card to keep during councilor phase.\n", GRN, RESET);
        }else{
            printf("發動 %s辦公處%s 能力, 在市長階段可額外挑選一張卡\n", GRN, RESET);
        }
        rt = 1;
    }
    return rt;
}

void goldmine(int playernow){
    //Gold mine 金礦坑 (20)
    if(checkbuilding(playernow, 20)){
        int isgold = 1;
        int getcards[4];
        for(int i=0; i<4; i++){
            getcards[i] = randomcard();
        }
        for(int i=0; i<4; i++){
            for(int j=i+1; j<4; j++){
                if(cost[getcards[i]] == cost[getcards[j]]){
                    isgold = 0;
                    break;
                } 
            }
            if(isgold == 0){
                break;
            }
        }
        if(isgold){ 
            if(p[playernow].isbot == 0){
                CLEAR
                int choice, invalid = 0;
                if(language == 0){
                    printf("Use %sgold mine's%s ability, get four cards and if they all have different cost. You can choose one and keep it.\n", GRN, RESET);
                }else{
                    printf("發動 %s金礦坑%s 能力, 抽取四張卡, 如果四張卡的花費皆不同則你可以選擇保留其中一張卡\n", GRN, RESET);
                }
                printf("=============================\n");
                for(int i=0; i<4; i++){
                    printf("(%d) %s Cost:%d VP:%d\n", i+1, cardNameData[language][getcards[i]], cost[getcards[i]], vp[getcards[i]]);
                }
                printf("=============================\n");
                if(language == 0){
                    printf("You got gold :> Choose one card to keep\n");
                }else{
                    printf("你挖到金礦了 :> 選一張卡放入手牌\n");
                }
                if(invalid) INVALID
                printf("Choice: ");
                scanf("%d", &choice);
                if(choice < 1 || choice > 4){
                    invalid = 1;
                }else{
                    printf("=============================\n");
                    if(language == 0){
                        printf("You chose to keep %s\n", cardNameData[language][getcards[choice-1]]);
                    }else{
                        printf("你選擇保留 %s\n", cardNameData[language][getcards[choice-1]]);
                    }
                    p[playernow].deck[p[playernow].cards] = getcards[choice-1];
                    p[playernow].cards++;
                    getcards[choice-1] = -1;
                    for(int i=0; i<4; i++){
                        if(getcards[i] != -1){
                            discardcard[getcards[i]]++;
                        }
                    }
                    PAUSE
                }
            }else{
                CLEAR
                int choice;
                if(language == 0){
                    printf("Use %sgold mine's%s ability, get four cards and if they all have different cost. You can choose one and keep it.\n", GRN, RESET);
                }else{
                    printf("發動 %s金礦坑%s 能力, 抽取四張卡, 如果四張卡的花費皆不同則你可以選擇保留其中一張卡\n", GRN, RESET);
                }
                printf("=============================\n");
                choice = rand() % 4;
                p[playernow].deck[p[playernow].cards] = getcards[choice];
                p[playernow].cards++;
                getcards[choice-1] = -1;
                for(int i=0; i<4; i++){
                    if(getcards[i] != -1){
                        discardcard[getcards[i]]++;
                    }
                }
                if(language == 0){
                    printf("Player %d got gold and kept one card\n", playernow+1);
                }else{
                    printf("玩家 %d 挖到金礦並保留了一張卡\n", playernow+1);
                }
                PAUSE
            }
        }else{
            CLEAR
            if(language == 0){
                printf("Use %sgold mine's%s ability, get four cards and if they all have different cost. You can choose one and keep it.\n", GRN, RESET);
            }else{
                printf("發動 %s金礦坑%s 能力, 抽取四張卡, 如果四張卡的花費皆不同則你可以選擇保留其中一張卡\n", GRN, RESET);
            }
            if(language == 0){
                printf("You didn't get gold :<\n");
            }else{
                printf("你沒挖到金礦 :<\\n");
            }
            for(int i=0; i<4; i++){
                discardcard[getcards[i]]++;
            }
            PAUSE
        }
        
    }
}