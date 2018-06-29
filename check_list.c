#include <check.h>
#include <stdlib.h>

#include "list.h"

//	struct node *list;
//
//	list = NULL;
//	list = createList();
//	printf("values of val are: %d, %d\n", list->val, list->next->val);
//	printf("is last? %d\n", isLast(list->next, list));
//
//	printf("address are %p, %p\n", list, list->next);
//	printf("address of %d is %p\n", 8, find(8, list));

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
}

END_TEST

Suite *make_list_suite(void) {
	Suite *s = suite_create("list");
	TCase *c = tcase_create("list");
	suite_add_tcase(s, c);
	tcase_add_test(c, test_createList);
	tcase_add_test(c, test_isEmpty);
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

