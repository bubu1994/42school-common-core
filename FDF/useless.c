
#include "./includes/fdf.h"

void	put_list_into_strings(t_pos **list, t_data mlx)
{
	t_pos	*scan;

	scan = *list;
	while (scan)
	{
		mlx_string_put(mlx.ptr, mlx.win, scan->x * gap_p(list, 'x'), scan->y * gap_p(list, 'y'), 0xFFFFFF, ft_itoa(scan->z));
		scan = scan->next;
	}
}

void	put_list_into_pixels(t_pos **list, t_img img)
{
	t_pos	*scan;

	scan = *list;
	while (scan)
	{
		if (scan->z == 0)
			put_my_pixel(&img, scan->x, scan->y, 0xFFFFFF);
		else
			put_my_pixel(&img, scan->x, scan->y, 0xFF0000);
		scan = scan->next;
	}
}

void	put_list_into_squares(t_pos **list, t_img img)
{
	t_pos	*scan;

	scan = *list;
	while (scan)
	{
		if (scan->z == 0)
			put_square_10(&img, scan->x * gap_p(list, 'x'), scan->y * gap_p(list, 'y'), 0xFFFFFF);
		else
			put_square_10(&img, scan->x * gap_p(list, 'x'), scan->y * gap_p(list, 'y'), 0x0000FF);
		scan = scan->next;
	}
}

void	put_one_horizontal(t_img image, t_pos **list, t_pos *a, t_pos *b)
{
	int	x;
	int	x2;

	x = a->x * GAP;
	x2 = b->x * GAP;
	while (x <= x2)
	{
		put_my_pixel(&image, x, a->y * GAP, 0xFFFFFF);
		x++;
	}
}

void	put_one_vertical(t_img image, t_pos **list, t_pos *a, t_pos *b)
{
	int	y;
	int	y2;

	y = a->y * GAP;
	y2 = b->y * GAP;
	while (y <= y2)
	{
		put_my_pixel(&image, a->x * GAP, y, 0xFFFFFF);
		y++;
	}
}

void	draw_straight_lines(t_pos **list, t_img image)
{
	t_pos	*scan;
	t_pos	*next_y_scan;

	scan = *list;
	next_y_scan = *list;
	while (next_y_scan->y != 1)
		next_y_scan = next_y_scan->next;
	while (scan->next != NULL)
	{
		put_one_horizontal(image, list, scan, scan->next);
		scan = scan->next;
	}
	scan = *list;
	while (next_y_scan != NULL)
	{
		put_one_vertical(image, list, scan, next_y_scan);
		scan = scan->next;
		next_y_scan = next_y_scan->next;
	}
}

void	put_square_10(t_img *img, int x, int y, int color)
{
	int	a;
	int	b;

	a = x;
	b = y;
	while (b < y + 10)
	{
		a = x;
		while (a < x + 10)
		{
			put_my_pixel(img, a, b, color);
			a++;
		}
		b++;
	}
}