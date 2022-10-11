#!/bin/bash
# GET /user/keys/:key_id
# {
#   "id": 1,
#   "title": "Public key",
#   "key": "ssh-rsa AAAAB3NzaC1yc2EAAAABJQAAAIEAiPWx6WM4lhHNedGfBpPJNPpZ7yKu+dnn1SJejgt4596k6YjzGGphH2TUxwKzxcKDKKezwkpfnxPkSMkuEspGRt/aZZ9wa++Oi7Qkr8prgHc4soW6NUlfDzpvZK2H5E7eQaSeP3SAwGmQKUFHCddNaP0L+hM7zhFNzjFvpaMgJw0=",
#   "created_at": "2014-08-01T14:47:39.080Z"
# }


# INFO
# https://docs.gitlab.com/ce/api/users.html#add-ssh-key
# https://askubuntu.com/questions/1162757/how-can-i-add-an-ssh-key-to-gitlab-through-a-bash-executable
# https://askubuntu.com/questions/1162782/how-to-authenticate-with-a-users-gitlab-username-and-password-through-a-bash-ex

# https://docs.gitlab.com/ee/api/#authentication

# token XQjBPCy8XKdXGKXULzG1


# POST /user/keys
# {
#   "id": "7507762",
#   "title": "Codam 1 day",
#   "key": "KEY_NAME",
#   "expires_at": "NEXT DAY"

# # id (required) - ID of specified user
# # title (required) - new SSH key’s title
# # key (required) - new SSH key
# # expires_at (optional) - The expiration date of the SSH key in ISO 8601 format (YYYY-MM-DDTHH:MM:SSZ)
# }

# curl https://gitlab.com/users/sign_in -X POST -d '{"Username or email": "demjula@gmail.com", "Password": "give_me_mywork6542_YES"}'

# curl -o /Users/ydemura/Desktop/cubik/test.html -b cookies.txt -c cookies.txt -d '{"Username or email": "demjula@gmail.com", "Password": "give_me_mywork6542_YES"}' https://gitlab.com/users/sign_in

curl https://gitlab.com/users/sign_in\
  --data 'Username or email=wrong' \
  --data 'Password=give_me_mywork6542_YES' \


# POST /user/keys
# {
#   "id": "7507762",
#   "title": "cd ~/.ssh && yes | ssh-keygen -t rsa -b 2048 -C "demjula@gmail.com" -f "/Users/ydemura/.ssh/id_rsa" -P "mypath" && pbcopy < id_rsa.pub",
#   "key": "THE KEY I GENERATED"
#   "expires_at": "2021-05-04T14:31:43+0200"
# }


# date -v+1d -> to add 1 day to current date 
# date +"%Y-%m-%dT%H:%M:%S%z" - get ISO format
# date -v+1d +"%Y-%m-%dT%H:%M:%S%z" - 2 commands together 


# date -v+1d +"%Y-%m-%dT%H:%M:%S%z" | pbcopy | pbpaste
