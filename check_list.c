#include <check.h>
#include <stdlib.h>

#include "list.h"


START_TEST(test_createList) {
	struct node *list;

	list = createList();

	fail_unless(list != NULL, "createList fail");
	fail_unless(list->next == NULL, "createList 指针未初始化为空");
}
END_TEST

START_TEST(test_isEmpty) {
	struct node *list;

	list = createList();
	fail_unless(isEmpty(list), "list不为空");

	list->next = malloc(sizeof(struct node));
	list->next->val = 5;
	list->next->next = NULL;
	fail_unless(!isEmpty(list), "list isEmpty fail");
	
}
END_TEST

START_TEST(test_isLast) {
	struct node *list;

	list = createList();
	list->next = malloc(sizeof(struct node));
	list->next->val = 5;
	list->next->next = NULL;
	fail_unless(isLast(list->next, list), "list isLast fail");

}
END_TEST

START_TEST(test_find) {
	struct node *list, *last;

	list = createList();
	last = list;
	last->next = malloc(sizeof(struct node));
	last = last->next;
	last->val = 5;
	last->next = NULL;

	last->next = malloc(sizeof(struct node));
	last = last->next;
	last->val = 6;
	last->next = NULL;

	fail_unless(last == find(6, list), "list find fail");
	fail_unless(NULL == find(0, list), "list find fail");

}
END_TEST

START_TEST(test_findPrevious) {
	struct node *list, *last;

	list = createList();
	last = list;
	last->next = malloc(sizeof(struct node));
	last = last->next;
	last->val = 5;
	last->next = NULL;

	last->next = malloc(sizeof(struct node));
	last = last->next;
	last->val = 6;
	last->next = NULL;

	fail_unless(NULL != findPrevious(6, list)->next, "list find fail");
	fail_unless(NULL == findPrevious(1000, list)->next, "list find fail");

}
END_TEST

START_TEST(test_delete) {
	struct node *list, *last;

	list = createList();
	last = list;
	last->next = malloc(sizeof(struct node));
	last = last->next;
	last->val = 5;
	last->next = NULL;

	last->next = malloc(sizeof(struct node));
	last = last->next;
	last->val = 6;
	last->next = NULL;

	delete(5, list);
	fail_unless(NULL == find(5, list), "list delete fail");
	fail_unless(NULL != find(6, list), "list delete fail");

}
END_TEST

START_TEST(test_insert) {
	struct node *list, *first, *second;

	list = createList();

	first = malloc(sizeof(struct node));
	first->val = 5;
	first->next = NULL;
	list->next = first;

	second = malloc(sizeof(struct node));
	second->val = 6;
	second->next = NULL;
	first->next = second;

	insert(7, list, first);
	fail_unless(first->next == find(7, list), "list delete fail");
	fail_unless(find(7, list)->next == second , "list delete fail");

}
END_TEST

START_TEST(test_makeEmpty) {
	struct node *list, *first, *second;

	list = createList();

	first = malloc(sizeof(struct node));
	first->val = 5;
	first->next = NULL;
	list->next = first;

	makeEmpty(list);
	fail_unless(list->next == NULL, "list makeEmpty fail");
	fail_unless(list != NULL, "list makeEmpty fail");
}
END_TEST

START_TEST(test_deleteList) {
	struct node *list, *first;

	list = createList();

	first = malloc(sizeof(struct node));
	first->val = 5;
	first->next = NULL;
	list->next = first;

	deleteList(list);
	// TODO 怎样测试
}
END_TEST

START_TEST(test_header) {
	struct node *list;

	list = createList();
	list->next = malloc(sizeof(struct node));
	list->next->val = 5;
	list->next->next = NULL;
	fail_unless(list == header(list), "list header fail");
	
}
END_TEST

Suite *make_list_suite(void) {
	Suite *s = suite_create("list");
	TCase *c = tcase_create("list");
	suite_add_tcase(s, c);
	tcase_add_test(c, test_createList);
	tcase_add_test(c, test_isEmpty);
	tcase_add_test(c, test_isLast);
	tcase_add_test(c, test_find);
	tcase_add_test(c, test_findPrevious);
	tcase_add_test(c, test_delete);
	tcase_add_test(c, test_insert);
	tcase_add_test(c, test_makeEmpty);
	tcase_add_test(c, test_deleteList);
	tcase_add_test(c, test_header);
	return s;
}

int main(void)
{
	int n;
	SRunner *r;
	r = srunner_create(make_list_suite());
	srunner_run_all(r, CK_NORMAL);
	n = srunner_ntests_failed(r);
	srunner_free(r);
	return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

