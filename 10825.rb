
arr=[]
 gets.to_i.times do
arr << gets.strip.split(' ')
end
arr = arr.sort do |a,b|
    a_name, *c = a
    a_a,a_b,a_c = c.map(&:to_i)
    b_name, *c = b
    b_a,b_b,b_c = c.map(&:to_i)
    if a_a == b_a && a_b == b_b && a_c == b_c
        a_name <=> b_name
    elsif a_a == b_a && a_b == b_b
        b_c   <=> a_c
    elsif a_a == b_a
        a_b  <=> b_b
    else
        b_a  <=> a_a
    end
end

print arr.map!(&:first).join("\n")