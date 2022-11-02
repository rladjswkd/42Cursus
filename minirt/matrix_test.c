#include <math.h>
typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

typedef struct s_mat
{
	double	arr[4][4];
	int		len;
}	t_mat;

double	vec4_dot(t_vec4 v1, t_vec4 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

t_vec4	arr_to_vec4(double arr[4])
{
	return ((t_vec4){arr[0], arr[1], arr[2], arr[3]});
}

t_mat	mat_mul(t_mat mat1, t_mat mat2)
{
	t_mat	ret;
	int		i;
	int		j;
	
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			ret.arr[i][j] = vec4_dot(arr_to_vec4(mat1.arr[i]),
				(t_vec4){mat2.arr[0][j], mat2.arr[1][j],
					mat2.arr[2][j], mat2.arr[3][j]});
	}
	ret.len = 4;
	return (ret);
}

// int	main(void) // mat_mul test - OK
// {
// 	t_mat	mat1 = {{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 8, 7, 6}, {5, 4, 3, 2}}, 4};
// 	t_mat	mat2 = {{{-2, 1, 2, 3}, {3, 2, 1, -1},{4, 3, 6, 5}, {1, 2, 7, 8}}, 4};

// 	t_mat	mult = mat_mul(mat1, mat2);
// 	return (0);
// }

t_mat	mat_submat(t_mat mat, int r, int c)
{
	t_mat	ret;
	int		ret_i;
	int		ret_j;
	int		i;
	int		j;

	i = -1;
	ret_i = -1;
	while (++i < mat.len)
	{
		if (i == r)
			continue ;
		++ret_i;
		j = -1;
		ret_j = -1;
		while (++j < mat.len)
		{
			if (j == c)
				continue ;
			ret.arr[ret_i][++ret_j] = mat.arr[i][j];
		}
	}
	ret.len = mat.len - 1;
	return (ret);
}

double	mat_determinant(t_mat mat)
{
	double	det;
	int		i;

	det = 0;
	if (mat.len == 2)
		return (mat.arr[0][0] * mat.arr[1][1] - mat.arr[0][1] * mat.arr[1][0]);
	i = -1;
	while (++i < mat.len)
		det += mat.arr[0][i]
			* (1 - 2 * (i % 2)) * mat_determinant(mat_submat(mat, 0, i));
	return (det);
}

// int	main(void) // mat_determinant test - OK
// {
// 	t_mat	mat = {{{-2, -8, 3, 5}, {-3, 1, 7, 3}, {1, 2, -9, 6}, {-6, 7, 7, -9}}, 4};
// 	double	res = mat_determinant(mat);
// }

// int	main(void) // mat_submat test - OK
// {
// 	t_mat	mat = {{{-6, 1, 1, 6}, {-8, 5, 8, 6}, {-1, 0, 8, 2}, {-7, 1, -1, 1}}, 4};
// 	t_mat	submat = mat_submat(mat, 2, 1);
// }

t_mat	mat_comatrix(t_mat mat)
{
	t_mat	comatrix;
	int		i;
	int		j;
	int		len;

	len = mat.len;	
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			comatrix.arr[i][j] = (1 - 2 * ((i + j) % 2))
				* mat_determinant(mat_submat(mat, i, j));
	}
	comatrix.len = len;
	return (comatrix);
}

// int	main(void) // mat_comatrix test - OK
// {
// 	t_mat	mat = {{{-5, 2, 6, -8}, {1, -5, 1, 8}, {7, 7, -6, -7}, {1, -3, 7, 4}}, 4};
// 	t_mat	comatrix = mat_comatrix(mat);
// }

t_mat	mat_transpose(t_mat	mat)
{
	return ((t_mat){{
		{mat.arr[0][0], mat.arr[1][0], mat.arr[2][0], mat.arr[3][0]},
		{mat.arr[0][1], mat.arr[1][1], mat.arr[2][1], mat.arr[3][1]},
		{mat.arr[0][2], mat.arr[1][2], mat.arr[2][2], mat.arr[3][2]},
		{mat.arr[0][3], mat.arr[1][3], mat.arr[2][3], mat.arr[3][3]}
		}, mat.len});
}

t_mat	mat_scale(t_mat mat, double scalar)
{
	t_mat	ret;
	int		i;
	int		j;
	int		len;

	len = mat.len;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
			ret.arr[i][j] = mat.arr[i][j] / scalar;
	}
	ret.len = len;
	return (ret);
}

t_mat	mat_inverse(t_mat mat) // this function is used only for rotation transformation matrices. they are always invertible so there is no need to calculate their determinatn.
{
	return (mat_scale(mat_transpose(mat_comatrix(mat)), mat_determinant(mat)));
}

// int	main(void) // mat_inverse test - OK
// {
// 	t_mat	mat = {{{-5, 2, 6, -8}, {1, -5, 1, 8}, {7, 7, -6, -7}, {1, -3, 7, 4}}, 4};
// 	t_mat	inv = mat_inverse(mat);
// }

typedef struct s_coordinate
{
	double	x;
	double	y;
	double	z;
}	t_coord;

typedef	t_coord	t_vec;

#define R_RAD	15 * M_PI / 180

t_mat	mat_rx(void)
{
	return ((t_mat){{
		{1, 0, 0, 0},
		{0, cos(RAD), -sin(RAD), 0},
		{0, sin(RAD), cos(RAD), 0},
		{0, 0, 0, 1}}, 4});
}

t_mat	mat_ry(void)
{
	return ((t_mat){{
		{cos(RAD), 0, sin(RAD), 0},
		{0, 1, 0, 0},
		{-sin(RAD), 0, cos(RAD), 0},
		{0, 0, 0, 1}}, 4});	
}

t_mat	mat_rz(void)
{
	return ((t_mat){{
		{cos(RAD), -sin(RAD), 0, 0},
		{sin(RAD), cos(RAD), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}}, 4});
}

t_vec4	mat_mul_vec4(t_mat mat, t_vec4 v)
{
	return ((t_vec4){vec4_dot(arr_to_vec4(mat.arr[0]), v),
		vec4_dot(arr_to_vec4(mat.arr[1]), v),
		vec4_dot(arr_to_vec4(mat.arr[2]), v),
		vec4_dot(arr_to_vec4(mat.arr[3]), v)});
}

t_vec4	vec_to_vec4(t_vec v)
{
	return ((t_vec4){v.x, v.y, v.z, 1});
}

t_vec	mat_rotate_arbitrary(t_vec forward, t_mat mat_op) // forward를 z축으로 변환 후 mat_op 적용하고 다시 원래의 vec으로 변환
{
	double	len_yz;
	t_mat	rx;
	t_mat	ry;
	t_vec4	res;

	// forward가 x, y, z일 때 별도로 처리해줘야 함.
	len_yz = sqrt(pow(forward.y, 2) + pow(forward.z, 2));
	rx = (t_mat){{{1, 0, 0, 0},
		{0, (forward.z / len_yz), -(forward.y / len_yz), 0},
		{0, (forward.y / len_yz), (forward.z / len_yz), 0},
		{0, 0, 0, 1}}, 4};
	ry = (t_mat){{{len_yz, 0, -forward.x, 0}, {0, 1, 0, 0},
		{forward.x, 0, len_yz, 0}, {0, 0, 0, 1}}, 4};
	res = mat_mul_vec4(mat_mul(mat_inverse(rx), mat_mul(mat_inverse(ry),
		mat_mul(mat_op, mat_mul(ry, rx)))), vec_to_vec4(forward));
	return ((t_vec){res.x, res.y, res.z});
}

int	main(void) // mat_rotate_arbitrary test - OK
{
	t_vec	ret1 = mat_rotate_arbitrary((t_vec){0.70710678118, 0.70710678118, 0}, mat_ry());
}