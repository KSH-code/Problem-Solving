# type should be one of :to_s, :to_i, :to_f, :to_r
def convert_to(ary, type)
  ary.each_with_object([]) do |row, new|
    new << row.collect { |elem| elem.send(type) }
  end
end

class Rational
  alias _to_s to_s
  def to_s
    denominator == 1 ? numerator.to_s : _to_s
  end
end

def reduced_row_echelon_form(ary)
  lead = 0
  rows = ary.size
  cols = ary[0].size
  rary = convert_to(ary, :to_r) # use rational arithmetic
  catch :done  do
    rows.times do |r|
      throw :done if cols <= lead
      i = r
      while rary[i][lead] == 0
        i += 1
        next unless rows == i

        i = r
        lead += 1
        throw :done if cols == lead
      end
      # swap rows i and r
      rary[i], rary[r] = rary[r], rary[i]
      # normalize row r
      v = rary[r][lead]
      rary[r].collect! { |x| x / v }
      # reduce other rows
      rows.times do |i|
        next if i == r

        v = rary[i][lead]
        rary[i].each_index { |j| rary[i][j] -= v * rary[r][j] }
      end
      lead += 1
    end
  end
  p rary
  rary
end

def check(arr, d)
  i = 0
  r = []
  while i + d < arr.size
    r << {
      unknowns: d.times.map { |j| arr[i + j].to_f } + [arr[i + d]]
    }
    i += 1
  end

  prev = nil
  cur = nil
  i = 0
  while i + d <= r.size
    cur = reduced_row_echelon_form(
      d.times.map { |j| r[i + j][:unknowns].dup }
    ).map(&:last)

    prev ||= cur
    return if prev != cur

    i += 1
  end

  i = -1
  cur.map do |v|
    i += 1
    v * arr[arr.size - d + i]
  end.sum.to_i
end

i = gets.to_i
i.times do
  _, *arr = gets.strip.split.map(&:to_i)
  1.upto(3) do |d|
    result = check(arr, d)
    if result
      puts result
      break
    end
  end
end
