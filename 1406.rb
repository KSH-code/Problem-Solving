class Node
  attr_accessor :left, :right, :letter
end

str = gets.strip

head = Node.new
tail = head

str.each_char do |c|
  tmp = Node.new
  tmp.letter = c
  tmp.left = tail
  tail.right = tmp
  tail = tmp
end

cursor = tail

n = gets.to_i
n.times do
  command, letter = gets.split(' ')
  case command
  when 'L'
    cursor = cursor.left if cursor.letter
  when 'D'
    cursor = cursor.right if cursor.right
  when 'B'
    if cursor.letter.nil?
      next
    elsif !cursor.right
      cursor.left.right = nil
      cursor = cursor.left
    else
      cursor.left.right = cursor.right
      cursor.right.left = cursor.left
      cursor = cursor.left
    end
  when 'P'
    tmp = Node.new
    tmp.letter = letter

    if cursor.right
      cursor.right.left = tmp
      tmp.right = cursor.right
    end

    tmp.left = cursor
    cursor.right = tmp

    cursor = tmp
  end
end

cursor = cursor.left while cursor.letter

str = ''
while cursor.right
  str << cursor.right.letter
  cursor = cursor.right
end

puts str
