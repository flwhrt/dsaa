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

Suite *make_list_suite(void) {
	Suite *s = suite_create("list");
	TCase *c = tcase_create("list");
	suite_add_tcase(s, c);
	tcase_add_test(c, test_createList);
	tcase_add_test(c, test_isEmpty);
	tcase_add_test(c, test_isLast);
	tcase_add_test(c, test_find);
	tcase_add_test(c, test_findPrevious);
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

