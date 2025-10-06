#include <stdio.h>

void hanoi(int n, char source, char target, char auxiliary);

int main(void) {
    // 円盤の数を定義
    int num_disks = 3;

    // ハノイの塔を解く関数を呼び出し
    // 3つの円盤を'A'から'C'へ、'B'を作業用に使って移動させる
    printf("円盤が%d個の場合の解法:\n", num_disks);
    hanoi(num_disks, 'A', 'C', 'B');

    return 0;
}

/**
 * @brief ハノイの塔を解く再帰関数
 * @param n 円盤の数
 * @param source 開始の杭
 * @param target 目標の杭
 * @param auxiliary 作業用の杭
 */
void hanoi(int n, char source, char target, char auxiliary) {
    // ベースケース：動かす円盤が1つになったら、それを目標に移動して終了
    if (n == 1) {
        printf("円盤 1 を %c から %c へ移動\n", source, target);
        return;
    }

    // ステップ1: n-1個の円盤を開始(source)から作業用(auxiliary)へ移動
    // このとき、目標(target)の杭が作業用になる
    hanoi(n - 1, source, auxiliary, target);

    // ステップ2: n番目の円盤を開始(source)から目標(target)へ移動
    printf("円盤 %d を %c から %c へ移動\n", n, source, target);

    // ステップ3: n-1個の円盤を作業用(auxiliary)から目標(target)へ移動
    // このとき、開始(source)の杭が作業用になる
    hanoi(n - 1, auxiliary, target, source);
}