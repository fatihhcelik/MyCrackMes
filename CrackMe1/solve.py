encoded = "QnhjsxjYj}y"
end = "#END#"
license_key = "#BEGIN#"
for i in encoded:
    license_key += chr(ord(i)-5)

license_key += end
print(license_key)