/*
** hs_split.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Apr 16 15:55:33 2016 antoine
** Last update Sat Apr 16 15:55:33 2016 antoine
*/

#include "../include/egc.h"

static t_hs     skip_word(t_hs *hs_pointer, t_hs separator)
{
  int           index;
  t_hs          hs;

  hs = *hs_pointer;
  index = hs_index_of(hs, separator);
  if (index == -1)
    {
      *hs_pointer = hs_new_empty();
      return (hs);
    }
  *hs_pointer = hs_slice(hs, index, hs.length);
  return (hs_slice(hs, 0, index));
}

static int      skip_separator(t_hs *hs_pointer, t_hs separator)
{
  int           index;
  t_hs          hs;

  hs = *hs_pointer;
  index = hs_index_of(hs, separator);
  if (index != 0)
    return (0);
  *hs_pointer = hs_slice(hs, separator.length, hs.length);
  return (1);
}

t_glist_hs      hs_split(t_hs hs, t_hs separator)
{
  t_glist_hs    list;
  t_hs          word;

  if (separator.length == 0)
    separator = hs_new_from_str(" ");
  list = glist_hs_new();
  if (!hs.length)
    return (list);
  while (1)
    {
      word = skip_word(&hs, separator);
      glist_hs_append(&list, word);
      if (!hs.length)
        break;
      if (!skip_separator(&hs, separator))
        break;
    }
  return (list);
}

t_glist_hs      hs_split_str(t_hs hs, const char *separator)
{
  return (hs_split(hs, hs_new_from_str(separator)));
}