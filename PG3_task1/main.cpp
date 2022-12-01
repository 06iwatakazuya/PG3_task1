#include <stdio.h>
#include <stdlib.h>

// 単方向リストの構造体定義
typedef struct cell
{
	int val;
	struct cell* next;
} CELL;

void create(CELL* head, int val);
void index(CELL* head);

int main() {
	int val;
	// 先頭のセルの宣言
	CELL head;
	head.next = nullptr;

	while (true) {
		printf("好きな数字を入力してください\n");

		scanf_s("%d", &val);

		// 最後尾にセルを追加
		create(&head, val);

		// リスト一覧の表示
		index(&head);
	}
	return 0;
}

// セルを新規作成する関数
void create(CELL* head, int val) {
	CELL* newCell;
	// 新規作成するセル分のメモリを確保する
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = val;
	newCell->next = nullptr;

	while (head->next != nullptr) {
		head = head->next;
	}
	head->next = newCell;
}

void index(CELL* list) {
	while (list->next != nullptr) {
		list = list->next;
		printf("[%d]", list->val);
	}
	printf("\n");
}