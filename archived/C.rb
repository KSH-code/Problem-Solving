# frozen_string_literal: true

number = gets.to_i
dp = Array.new(number + 1)
1.upto(number) do |n|
  k = 0
  cur = 1
  max = 0
  while cur <= n
    max += 1
    cur *= 2
  end
  cur = 1
  dp[n] = Array.new(max, 0)
  while cur <= n
    pre = n - cur
    if pre.zero?
      dp[n][k] = 1
    else
      dp[n][k] = 0
      i = 0
      tt = 1
      while tt <= pre
        dp[n][k] = (dp[n][k] + dp[pre][i]) % 1_000_000_000
        tt *= 2
        i += 1
      end
    end
    cur *= 2
    k += 1
  end
end
puts dp[number].sum % 1_000_000_000
