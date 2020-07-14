# frozen_string_literal: true

lines = gets.to_i

score_map = {}
at_index_by_name = {}
1.upto(lines) do |i|
  name, score = gets.split
  score = score.to_i

  score_map[name] ||= 0
  score_map[name] += score

  at_index_by_name[name] ||= []
  at_index_by_name[name] << [score_map[name], i]
end

scores = score_map.to_a.sort_by(&:last)
puts(
  scores
    .select { |score| scores.last.last == score.last }
    .min_by { |score| at_index_by_name[score.first].find { |e| e.first >= score.last }.last }
    .first
)
