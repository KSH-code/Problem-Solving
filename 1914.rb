n = gets.to_i

def go(n, s, m, e)
    if n == 1
        puts "#{s} #{e}"
        return
    end
    go(n-1, s, e, m)
    puts "#{s} #{e}"
    go(n-1, m, s, e)
end

if n > 20
    puts 2**n-1
else
    puts 2**n-1
    go(n, 1, 2, 3)
end
