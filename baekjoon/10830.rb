@n, b = gets.split.map(&:to_i)

@map = {}
@map[1] = @n.times.map { gets.split.map(&:to_i).map { |v| v % 1000 } }
def matrix_mul(a, b)
  @n.times.map do |i|
    @n.times.map do |j|
      @n.times.map do |k|
        a[i][k] * b[k][j]
      end.sum % 1000
    end
  end
end

def mul(n)
  return @map[n] if @map[n]
  return @base_arr if n == 1

  @map[n] = matrix_mul(mul(n / 2), mul(n / 2))
  return @map[n] if n.even?

  @map[n] = matrix_mul(@map[1], @map[n])
end

puts(mul(b).map { |r| r.join(' ') }.join("\n"))
