import random

def food_delivery_chatbot(user_input):
    

    if "order" in user_input.lower():
        responses = ["Sure! What would you like to order?", "Certainly! What's your desired order?"]
        return random.choice(responses)
    elif "menu" in user_input.lower() or "options" in user_input.lower():
        responses = ["Here is our menu: [list of menu items]", "Our menu includes: [list of menu items]"]
        return random.choice(responses)
    elif "delivery" in user_input.lower():
        responses = ["Where would you like the food to be delivered?", "Please provide your delivery address."]
        return random.choice(responses)
    elif "payment" in user_input.lower() or "pay" in user_input.lower():
        responses = ["How would you like to pay for your order?", "We accept various payment methods. How would you prefer to pay?"]
        return random.choice(responses)
    elif any(word in user_input.lower() for word in ["help", "support", "assistance"]):
        responses = ["Please contact our customer support at [phone number].", "Our customer support can be reached at [phone number]."]
        return random.choice(responses)
    elif any(word in user_input.lower() for word in ["cancel", "change", "modify"]):
        responses = ["To make changes to your order, please contact our customer support.", "For any modifications to your order, kindly reach out to our customer support."]
        return random.choice(responses)
    elif any(word in user_input.lower() for word in ["track", "delivery status"]):
        responses = ["To track the status of your delivery, please visit [website or tracking link].", "You can track your delivery status by visiting [website or tracking link]."]
        return random.choice(responses)
    elif "vegan" in user_input.lower() or "vegetarian" in user_input.lower():
        responses = ["We have a variety of vegan and vegetarian options. Here are a few: [list of items].", "Our menu offers several vegan and vegetarian choices, including: [list of items]."]
        return random.choice(responses)
    elif "gluten-free" in user_input.lower() or "allergies" in user_input.lower():
        responses = ["We offer gluten-free options. Please let us know about your specific allergies, and we'll ensure a safe preparation of your order.", "We take allergies seriously. Inform us about your specific requirements, and we'll cater to them."]
        return random.choice(responses)
    elif any(word in user_input.lower() for word in ["hours", "operation", "open"]):
        responses = ["We are open from [opening time] to [closing time].", "Our business hours are from [opening time] until [closing time]."]
        return random.choice(responses)
    else:
        responses = ["I'm sorry, I didn't understand. Can you please rephrase your request?", "Apologies, I couldn't comprehend that. Could you rephrase your query?"]
        return random.choice(responses)

while True:
    user_input = input("User: ")
    print("FBot:", food_delivery_chatbot(user_input))
