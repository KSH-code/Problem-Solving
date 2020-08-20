# frozen_string_literal: true

lines = gets.to_i
lines.times do
  xyz = gets.split(' ').map(&:to_i).sort.reverse
  if xyz[0] == xyz[1]
    print 'YES', "\n"
    print "#{xyz[0]} #{xyz[2]} 1", "\n"
  else
    print 'NO', "\n"
  end
end
