n = gets.to_i

def matrix_mul(a, b)
  [
    [
      (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % 1_000_000_007,
      (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % 1_000_000_007
    ],
    [
      (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % 1_000_000_007,
      (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % 1_000_000_007
    ]
  ]
end

@map = {}
def mul(n)
  return @map[n] if @map[n]
  return [[1, 1], [1, 0]] if n == 1

  @map[n] = matrix_mul(mul(n / 2), mul(n / 2))
  return @map[n] if n.even?

  @map[n] = matrix_mul([[1, 1], [1, 0]], @map[n])
end

puts(mul(n)[1][0])
