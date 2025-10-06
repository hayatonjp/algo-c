#include <stdio.h>

// インデントを印字するためのヘルパー関数
void print_indent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  "); // 深さ1ごとにスペースを2つ表示
    }
}

// 可視化機能付きのhanoi関数
void hanoi(int n, char source, char target, char auxiliary, int depth) {
    // --- この階層の関数が呼ばれたことを表示 ---
    print_indent(depth);
    printf("--> hanoi(n=%d, 開始=%c, 目標=%c, 作業=%c) が呼ばれました\n", n, source, target, auxiliary);

    // ベースケース：n=1 の場合
    if (n == 1) {
        print_indent(depth + 1);
        printf("円盤 1 を %c から %c へ移動\n", source, target);
        
        // --- この階層の関数が終了することを表示 ---
        print_indent(depth);
        printf("<-- hanoi(n=%d) の仕事が完了\n", n);
        return;
    }

    // ステップ1: n-1個の円盤を開始(source)から作業用(auxiliary)へ移動
    hanoi(n - 1, source, auxiliary, target, depth + 1);

    // ステップ2: n番目の円盤を移動
    print_indent(depth + 1);
    printf("円盤 %d を %c から %c へ移動\n", n, source, target);

    // ステップ3: n-1個の円盤を作業用(auxiliary)から目標(target)へ移動
    hanoi(n - 1, auxiliary, target, source, depth + 1);

    // --- この階層の関数が終了することを表示 ---
    print_indent(depth);
    printf("<-- hanoi(n=%d) の仕事が完了\n", n);
}

int main(void) {
    int num_disks = 3;

    printf("円盤が%d個の場合の解法（呼び出し過程の可視化）:\n", num_disks);
    hanoi(num_disks, 'A', 'C', 'B', 0); // 最初の呼び出しは深さ0からスタート

    return 0;
}