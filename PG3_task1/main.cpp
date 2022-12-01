#include <stdio.h>
#include <stdlib.h>

// �P�������X�g�̍\���̒�`
typedef struct cell
{
	int val;
	struct cell* next;
} CELL;

void create(CELL* head, int val);
void index(CELL* head);

int main() {
	int val;
	// �擪�̃Z���̐錾
	CELL head;
	head.next = nullptr;

	while (true) {
		printf("�D���Ȑ�������͂��Ă�������\n");

		scanf_s("%d", &val);

		// �Ō���ɃZ����ǉ�
		create(&head, val);

		// ���X�g�ꗗ�̕\��
		index(&head);
	}
	return 0;
}

// �Z����V�K�쐬����֐�
void create(CELL* head, int val) {
	CELL* newCell;
	// �V�K�쐬����Z�����̃��������m�ۂ���
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