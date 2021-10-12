n = gets.to_i

def traverse(l, r, ll, rr)
  return if l > r || ll > rr

  result = @post_order[rr]
  print "#{result} "

  in_index = @in_index[result]
  left_count = in_index - l

  traverse(l, in_index - 1, ll, ll + left_count - 1)
  traverse(in_index + 1, r, ll + left_count, rr - 1)
end

@in_order = gets.split.map(&:to_i)
@in_index = @in_order.map.with_index.to_h
@post_order = gets.split.map(&:to_i)

traverse(0, n - 1, 0, n - 1)
