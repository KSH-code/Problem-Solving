arr = []
gets.to_i.times do
    arr << gets.to_i
end

if arr[1] - arr[0] + arr[1] == arr[2]
    print arr.last + arr[1] - arr[0]
else
    print arr[1] / arr[0] * arr.last
end