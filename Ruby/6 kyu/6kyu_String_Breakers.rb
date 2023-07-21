def string_breakers(n, st)
  st.gsub(' ', '').scan(/.{1,#{n}}/).join("\n")
end