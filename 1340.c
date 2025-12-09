#include <stdio.h>
#include <stdlib.h>

void pq_push(int *h, int *hsz, int x)
{
  int i = (*hsz)++;
  h[i] = x;
  while (i > 0)
  {
    int p = (i - 1) / 2;
    if (h[p] >= h[i])
    {
      break;
    }
    int t = h[p];
    h[p] = h[i];
    h[i] = t;
    i = p;
  }
}

int pq_pop(int *h, int *hsz)
{
  if (*hsz == 0)
  {
    return -1;
  }
  int ret = h[0];
  h[0] = h[--(*hsz)];
  int i = 0;
  while (1)
  {
    int l = 2 * i + 1;
    int r = l + 1;
    int m = i;
    if (l < *hsz && h[l] > h[m])
    {
      m = l;
    }
    if (r < *hsz && h[r] > h[m])
    {
      m = r;
    }
    if (m == i)
    {
      break;
    }
    int tmp = h[i];
    h[i] = h[m];
    h[m] = tmp;
    i = m;
  }
  return ret;
}

int main(void)
{
  int n;
  while (scanf("%d", &n) == 1)
  {
    int *st = malloc(n * sizeof(int));
    int *q = malloc(n * sizeof(int));
    int *pq = malloc(n * sizeof(int));
    int top = 0;
    int head = 0;
    int tail = 0;
    int hsz = 0;
    int ok_stack = 1;
    int ok_queue = 1;
    int ok_pq = 1;
    for (int i = 0; i < n; ++i)
    {
      int op, val;
      scanf("%d %d", &op, &val);
      if (op == 1)
      {
        st[top++] = val;
        q[tail++] = val;
        pq_push(pq, &hsz, val);
      }
      else if (op == 2)
      {
        int x;
        if (top > 0)
        {
          x = st[--top];
          if (x != val)
          {
            ok_stack = 0;
          }
        }
        else
        {
          ok_stack = 0;
        }

        if (head < tail)
        {
          x = q[head++];
          if (x != val)
          {
            ok_queue = 0;
          }
        }
        else
        {
          ok_queue = 0;
        }

        x = pq_pop(pq, &hsz);
        if (x == -1)
        {
          ok_pq = 0;
        }
        else
        {
          if (x != val)
          {
            ok_pq = 0;
          }
        }
      }
    }
    int cnt = 0;
    if (ok_stack) ++cnt;
    if (ok_queue) ++cnt;
    if (ok_pq) ++cnt;
    if (cnt == 0)
    {
      printf("impossible\n");
    }
    else if (cnt > 1)
    {
      printf("not sure\n");
    }
    else
    {
      if (ok_stack)
      {
        printf("stack\n");
      }
      else if (ok_queue)
      {
        printf("queue\n");
      }
      else
      {
        printf("priority queue\n");
      }
    }
    free(st);
    free(q);
    free(pq);
  }
  return 0;
}
