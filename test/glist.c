/*
** glist.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 15:00:41 2016 antoine
** Last update Sat Apr 16 15:00:41 2016 antoine
*/

#include "../src/egc_private.h"
#include "test.h"

static void     test_glist_hs(void)
{
  t_glist_hs    l;
  t_hs          s;

  l = glist_hs_new();

  s = hs_new_from_str("a");
  glist_hs_append(&l, s);
  s = hs_new_from_str("b");
  glist_hs_append(&l, s);
  s = hs_new_from_str("c");
  glist_hs_append(&l, s);
  ASSERT(hs_equals_str(glist_hs_get(&l, 0), "a"));
  ASSERT(hs_equals_str(glist_hs_get(&l, 1), "b"));
  ASSERT(hs_equals_str(glist_hs_get(&l, 2), "c"));
}

void            test_suite_glist(void)
{
  t_glist_int   l;

  l = glist_int_new();
  ASSERT(glist_int_size(&l) == 0);
  glist_int_append(&l, 0);
  ASSERT(glist_int_size(&l) == 1);
  ASSERT(glist_int_get(&l, 0) == 0);
  glist_int_append(&l, 1);
  glist_int_append(&l, 2);
  ASSERT(glist_int_size(&l) == 3);
  ASSERT(glist_int_get(&l, 0) == 0);
  ASSERT(glist_int_get(&l, 1) == 1);
  ASSERT(glist_int_get(&l, 2) == 2);
  test_glist_hs();
}
